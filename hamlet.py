num_lines = 0;
with open('hamlet_data.h', 'w') as dst:
    dst.write('const char *HAMLET_LINES[] = {\n')
    with open('hamlet.txt', 'r') as src:
        for line in src.readlines():
            dst.write('"' + line.strip().replace('"', '') + '",\n')
            num_lines += 1
    dst.write("};\nconst long HAMLET_NUM_LINES = " + str(num_lines) + ";\n")
