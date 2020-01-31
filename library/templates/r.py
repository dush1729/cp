import os
import sys

def get_filename(filename, extension):
	filename = str(filename)
	if len(filename) == 1:
		return "0" + filename + "." + extension
	else:
		return filename + "." + extension

l, r = int(sys.argv[1]), int(sys.argv[2])
for file in range(l, r + 1):
	if file < 50:
		os.system("cp 00.cpp " + get_filename(file, "cpp"))
	else:
		os.system(">" + get_filename(file, "py"))