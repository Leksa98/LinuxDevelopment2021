set $count = 0

break range.c:24 if ($count++ >= 27 && $count <= 35)
	command 1
	echo @@@
	printf "%d %d %d %d\n", M, N, S, i
	continue
end

run -100 100 3 > /dev/null

quit
