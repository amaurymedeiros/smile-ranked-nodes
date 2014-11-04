all:
	script/copy_libs.sh
	g++ main.cpp -l smile -o example

