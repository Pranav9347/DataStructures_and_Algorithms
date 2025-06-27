def ArrayChallenge(strArr):
    word = strArr[0]
    words = strArr[1].split(",")
    for i in range(1,len(word)):
        if word[:i] in words:
            if word[i:] in words:
                return word[:i] + "," + word[i:]
    return "not possible"

# out = ArrayChallenge(["hellocat","apple,bat,cat,goodbye,hello,yellow,why"])
out = ArrayChallenge(["baseball","a,all,b,ball,bas,base,cat,code,d,e,quit"])
print(out)
challenge_token = "ov5ne7xad9c"
ans = out[::-1]+':'+challenge_token[::-1]
print(ans)