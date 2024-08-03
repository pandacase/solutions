import os
import glob


def clean_out_files(directory):
    # 构建通配符路径，匹配以 .out 结尾的文件
    pattern = os.path.join(directory, '*.out')

    # 使用 glob.glob 查找所有匹配的文件
    files = glob.glob(pattern)

    # 删除每个文件
    for file in files:
        try:
            os.remove(file)
            print(f"Deleted: {file}")
        except OSError as e:
            print(f"Error deleting {file}: {e}")


directory = './Debug/'
clean_out_files(directory)
