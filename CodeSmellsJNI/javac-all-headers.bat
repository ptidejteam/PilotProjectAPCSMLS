dir /s /B *.java > sources.txt
javac -d bin/ -h bin/headers/ @sources.txt
del sources.txt