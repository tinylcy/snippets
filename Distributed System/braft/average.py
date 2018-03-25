with open('./data') as f:
    lines = f.readlines()

sum = 0
for line in lines:
    if line[len(line)-3:] == "ms\n":
        # print(float(line[:len(line)-3]))
        sum += float(line[:len(line)-3])
    else:
        # print(1000 * float(line[:len(line)-2]))
        sum += 1000 * float(line[:len(line)-2])

print(sum / len(lines))

    