# Makefile
# 使用 `make n` 命令编译并运行 Scripts/n.cc 文件

# 默认目标
.PHONY: all
all: 

# 目标为任意整数
%:
	@g++ Scripts/$*.cc -o Debug/$*.out
	@echo "[+] g++ Scripts/$*.cc -o Debug/$*.out"
	@echo "[+] ./Debug/$*.out"
	@echo "[+] Get outputs:"
	@./Debug/$*.out


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
