TEST1_RESULT=$(echo "SHA1 \"Something" | ./rhasher | tail -n1)
TEST1_EXPECTATION=$(echo -n "Something" | sha1sum | tr -d ' ' | tr -d '-')

echo "$TEST1_RESULT"
echo "$TEST1_EXPECTATION"

if ["$TEST1_RESULT" != "$TEST1_EXPECTATION"]; then
	echo "sha1 string test failed"
else 
	echo "sha1 string test passed"
fi

TEST2_RESULT=$(echo "SHA1 rhasher.c" | ./rhasher | tail -n1)
TEST2_EXPECTATION=$(echo sha1sum rhasher.c | tr -d ' ' | tr -d 'rhasher.c')

echo "$TEST2_RESULT"
echo "$TEST2_EXPECTATION"

if ["$TEST2_RESULT" != "$TEST2_EXPECTATION"]; then
	echo "sha1 file test failed"
else 
	echo "sha1 file test passed"
fi

TEST3_RESULT=$(echo "MD5 \"Something" | ./rhasher | tail -n1)
TEST3_EXPECTATION=$(echo -n "Something" | md5sum | tr -d ' ' | tr -d '-')

echo "$TEST3_RESULT"
echo "$TEST3_EXPECTATION"

if ["$TEST3_RESULT" != "$TEST3_EXPECTATION"]; then
	echo "md5 string test failed"
else 
	echo "md5 string test passed"
fi

TEST4_RESULT=$(echo "MD5 rhasher.c" | ./rhasher | tail -n1)
TEST4_EXPECTATION=$(echo md5sum rhasher.c | tr -d ' ' | tr -d 'rhasher.c')

echo "$TEST4_RESULT"
echo "$TEST4_EXPECTATION"

if ["$TEST4_RESULT" != "$TEST4_EXPECTATION"]; then
	echo "md5 file test failed"
else 
	echo "md5 file test passed"
fi