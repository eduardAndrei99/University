"""

"""


def interclasare(v, left, right, mid):
    
    aux = []
    for i in range(0,right+1):
        aux.append(0)
    i = left
    j = mid + 1
    contor = left - 1
    while i <= mid and j <= right:
        if v[i] <= v[j]:
            contor = contor + 1
            aux[contor] = v[i]
            i = i +1
        else:
            contor = contor + 1
            aux[contor] = v[j]
            j = j + 1
    
    while (i<=mid):
        contor = contor + 1
        aux[contor] = v[i]
        i = i + 1
    while (j<=right):
        contor = contor + 1
        aux[contor] = v[j]
        j = j + 1
            
    for k in range(left, right+1):
        v[k] = aux[k]
    

def mergeSort(v, left, right):
    if left >= right:
        return
    
    mijloc = (left+right) // 2
    
    mergeSort(v, left, mijloc)
    mergeSort(v,mijloc + 1, right)
    interclasare(v, left, right, mijloc)
 
 
v = [2, 3, 1, 4, 5, 15, 20, 1, 0, -4, 100, 24, 1]
#selectionSort(v)
#bubbleSort(v)
mergeSort(v, 0, len(v) - 1)

print(v)

