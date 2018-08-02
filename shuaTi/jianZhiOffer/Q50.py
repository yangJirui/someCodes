# -*- coding: utf-8 -*-


def find_first_once(string):

    str_dict = {}
    first_char = string[0]


    for a_char in string[::-1]:
        if a_char in str_dict:
            str_dict[a_char] += 1
        else:
            str_dict[a_char] = 1
            first_char = a_char

    return first_char

if __name__ == '__main__':
    print find_first_once("abaccdeff")