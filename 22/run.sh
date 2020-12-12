if ! g++ -o p1 p1.cpp || ! g++ -o p2 p2.cpp; then
	exit 0
fi

if [ $# -ne 2 ]; then
	echo "Usage: ./run.sh <question number> <input data>"
	exit 0
fi

echo "running q$1 on $2 input"
./p$1 < input.$2