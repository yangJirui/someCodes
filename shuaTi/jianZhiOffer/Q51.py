# -*-coding: utf-8 -*-


def find_reverse_pair(raw_list):

    if(raw_list is None or len(raw_list)==0):
        return 0, None
    
    if(len(raw_list)==1):
        return 0, raw_list

    mid = len(raw_list)//2
    left_count, left_arry = find_reverse_pair(raw_list[: mid+1])

    right_count, right_arry = find_reverse_pair(raw_list[mid+1: ])
    

    left_index = len(left_arry)-1
    right_index = len(right_arry)-1
    
    count = 0
    merged_list = []
    while(left_index>=0 and right_index>=0):
        if left_arry[left_index] > right_arry[right_index]:
            merged_list.append(left_arry[left_index])
            count += len(right_arry)
            left_index -= 1
        else:
            merged_list.append(right_arry[right_arry])
            right_arry -= 1
    

    if(left_index==0):
        merged_list.append(left_arry[left_index])
    if(right_index==0):
        merged_list.append(right_arry[right_index])

    return left_count+count+right_count, merged_list[::-1]


if __name__ == '__main__':

    print find_reverse_pair([7, 5, 6, 4])
