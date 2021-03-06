bin_srcs :=
lib_name := algo

# all dirs
build_dir := build

# all dirs
lib_build_dir := $(build_dir)/lib
all_build_dirs := $(lib_build_dir) \
	$(build_dir)/src \
	$(build_dir)/leetcode \
	$(build_dir)/lintcode

# lib srcs and objs 
lib_srcs := $(wildcard src/*.cpp)
lib_objs := $(addprefix $(build_dir)/, $(lib_srcs:.cpp=.o))
# bin srcs and objs
bin_objs := $(addprefix $(build_dir)/, $(bin_srcs:.cpp=.o))
bin_targets := $(bin_objs:.o=.bin)

# dependencies
deps := $(lib_objs:.o=.d)

# flags
CXXFLAGS := -O2 -std=c++11 -Iinclude -MMD -MP
LDFLAGS := -lglog
ifneq ($(strip $(lib_objs)),)
lib_target := $(lib_build_dir)/lib$(lib_name).a
LDFLAGS += -L$(lib_build_dir) -l$(lib_name)
endif


.PHONY: all clean run

run: | $(bin_targets)
	@echo '---- make run ----'
	@./$(bin_targets)

# make dirs
$(all_build_dirs):
	mkdir -p $@

ifneq ($(strip $(lib_target)),)
$(lib_target): $(lib_objs) | $(lib_build_dir)
	ar rcs $@ $^
endif

$(bin_targets): %.bin : %.o $(lib_target)
	$(CXX) $< -o $@ $(LDFLAGS)

$(build_dir)/%.o: %.cpp | $(all_build_dirs)
	$(CXX) $(CXXFLAGS) -c -o $@ $<

#
# clean
#
clean:
	rm -rf $(all_build_dirs)

-include $(deps)
