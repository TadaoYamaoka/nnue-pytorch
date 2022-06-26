CC = g++
CFLAGS = -std=c++17 -DEVAL_LEARN -fno-exceptions -fno-rtti -Wextra -Ofast -MMD -MP -fpermissive -msse4.1 -mbmi -mbmi2 -mavx2
LDFLAGS = -lpthread -flto
INCLUDE = -I../YaneuraOu/source
LIB = 

target = filter_psv
sources = main.cpp
yaneuraou_sources = benchmark.cpp bitboard.cpp engine/yaneuraou-engine/yaneuraou-search.cpp eval/evaluate.cpp eval/evaluate_bona_piece.cpp eval/evaluate_mir_inv_tools.cpp eval/material/evaluate_material.cpp eval/nnue/evaluate_nnue.cpp eval/nnue/evaluate_nnue_learner.cpp eval/nnue/features/half_kp.cpp eval/nnue/features/half_relative_kp.cpp eval/nnue/nnue_test_command.cpp extra/book/apery_book.cpp extra/book/book.cpp extra/book/makebook2019.cpp extra/mate/mate1ply_without_effect.cpp extra/mate/mate1ply_with_effect.cpp extra/mate/mate_n_ply.cpp extra/sfen_packer.cpp extra/test_cmd.cpp learn/learner.cpp learn/learning_tools.cpp learn/multi_think.cpp misc.cpp movegen.cpp movepick.cpp position.cpp thread.cpp timeman.cpp tt.cpp types.cpp usi.cpp usi_option.cpp
objects = $(addprefix obj/, $(sources:.cpp=.o))
yaneuraou_objects = $(addprefix obj/, $(yaneuraou_sources:.cpp=.o))

$(target): $(objects) $(yaneuraou_objects)
	$(CC) -o $@ $^ $(LIB) $(LDFLAGS) $(CFLAGS)

obj/%.o: %.cpp
	@[ -d $(dir $@) ] || mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INCLUDE) -o $@ -c $<

obj/%.o: ../YaneuraOu/source/%.cpp
	@[ -d $(dir $@) ] || mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INCLUDE) -o $@ -c $<

all: $(target)

clean:
	rm -f $(objects) $(yaneuraou_objects) $(target)
