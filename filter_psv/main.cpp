#include "types.h"
#include "config.h"
#include "usi.h"
#include "thread.h"
#include "position.h"
#include "learn/learn.h"

int main(int argc, char* argv[])
{
	if (argc < 3) {
		std::cout << "usage: filter_psv psv out" << std::endl;
		return 1;
	}
	const auto psv_path = argv[1];
	const auto out_path = argv[2];

	USI::init(Options);
	Bitboards::init();
	Position::init();
	Search::init();
	Threads.set(1);
	Eval::init();

	is_ready();

	std::ifstream ifs(psv_path, std::ios::in | std::ios::binary);
	std::ofstream ofs(out_path, std::ios::out | std::ios::binary);

	Position pos;
	Learner::PackedSfenValue psv;

	size_t input_cnt = 0;
	size_t output_cnt = 0;
	while (ifs.read(reinterpret_cast<char*>(&psv), sizeof(Learner::PackedSfenValue))) {
		input_cnt++;
		StateInfo si;
		pos.set_from_packed_sfen(psv.sfen, &si, Threads.main());
		const auto pv_size = Learner::qsearch(pos).second.size();
		//std::cout << pos;
		//std::cout << pv_size << std::endl;
		if (pv_size == 0) {
			output_cnt++;
			ofs.write(reinterpret_cast<char*>(&psv), sizeof(Learner::PackedSfenValue));
		}
	}

	std::cout << "input  : " << input_cnt << std::endl;
	std::cout << "output : " << output_cnt << std::endl;

	return 0;
}
