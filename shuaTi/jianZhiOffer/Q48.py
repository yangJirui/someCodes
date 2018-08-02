# -*-coding:utf-8 -*-

def find_longest_substr(input_str):
    if input_str is None:
        return None, 0


    char_dict = dict(zip([chr(ord('a')+i) for i in range(26)], 26*[-1]))
    print char_dict
    substr_st = 0
    
    max_len = 0
    substr_len = 0
    for i, a_char in enumerate(input_str):
        if(char_dict[a_char]==-1):
            char_dict[a_char] = i
            substr_len +=1
            if(substr_len>max_len):
                max_len = substr_len
        else:
            substr_st = char_dict[a_char]+1
            substr_len = i - char_dict[a_char] 
            char_dict[a_char] = i
            if(substr_len>max_len):
                max_len = substr_len

    return max_len, substr_st

if __name__ == '__main__':
    print find_longest_substr("arbabcacfr")
            



