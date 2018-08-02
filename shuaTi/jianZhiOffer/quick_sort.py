# -*- coding: utf-8 -*-
import numpy as np

def quick_sort(in_list, st, end):

    if st >=end:
        return

    rand_index = np.random.randint(st, end)

    compare_value = in_list[rand_index]

    in_list[rand_index], in_list[end-1] = in_list[end-1], in_list[rand_index]


    small = st-1

    for j in range(st, end-1):
        if in_list[j] < compare_value:
            small +=1
            in_list[small], in_list[j] = in_list[j], in_list[small]
    
    small +=1
    in_list[small], in_list[end-1] = in_list[end-1], in_list[small]

    quick_sort(in_list, st=st, end=small)
    quick_sort(in_list, st=small+1, end=end)



if __name__ == "__main__":
    
    a = [3, 4, 2, 1, 5]

    quick_sort(a, 0, len(a))

    print a 
