# Makefile
# 使用 `make n` 命令编译并运行 Scripts/n.cc 文件

# 默认目标
.PHONY: all
all: 

# 目标为任意整数
%:
	@g++ Scripts/$*.cc -o Debug/$*.out
	@./Debug/$*.out


# Git push 目标
.PHONY: push
push:
	git add .
	git commit -m "$(m)"
	git push -u origin main
