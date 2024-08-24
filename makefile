# Makefile
# 使用 `make n` 命令编译并运行 Scripts/n.cc 文件

# 默认目标
.PHONY: all
all: 

# 查找 Scripts 目录中的所有 .cc 文件并编译它们
FILES := $(shell find Scripts -name "*.cc")

# 将文件名转换为相应的可执行文件路径
OUTPUTS := $(patsubst Scripts/%.cc, Debug/%.out, $(FILES))

# 编译所有找到的 .cc 文件
all: $(OUTPUTS)

# 编译特定编号的文件
%:
	@file=$(shell find Scripts -name "$*.cc"); \
	if [ -f "$$file" ]; then \
		outfile="Debug/$*.out"; \
		mkdir -p $$(dirname $$outfile); \
		g++ $$file -o $$outfile; \
		echo "[+] g++ $$file -o $$outfile"; \
		echo "[+] Running $$outfile"; \
		./$$outfile; \
	else \
		echo "No source file found for target $*"; \
		exit 1; \
	fi


# Git push 目标
.PHONY: push
push:
	@git add .
	@echo "[+] git add ."
	@git commit -m "$(m)"
	@echo "[+] git commit -m '$(m)'"
	@git push -u origin main
	@echo "[+] git push -u origin main"


# clean 目标
.PHONY: clean
clean:
	@rm -rf ./Debug/*.out
	@echo "[+] rm -rf ./Debug/*.out"
	@echo "[+] Successed"
