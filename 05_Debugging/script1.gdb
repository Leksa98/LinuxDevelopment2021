break range.c:17 if i % 5 == 0
	command 1
	echo @@@
	printf "%d %d %d %d\n", M, N, S, i
	continue
end

run 1 12 > /dev/null

quit
