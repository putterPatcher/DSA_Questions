def rotate(matrix: list[list[int]]) -> None:
     if len(matrix)%2 == 0:
        arr_1 = []
        for i in range(len(matrix)//2-1):
            arr_1.append(matrix[i][i+1:len(matrix)-1-i])
        for i in range(1,len(matrix)//2):
            arr_1.append(matrix[len(matrix)//2+i][len(matrix)//2-i:len(matrix)//2+i])
        arr_2 = []
        for i in range(len(matrix)//2-1):
            arr = []
            for j in range(i+1,len(matrix)-1-i):
                arr.append(matrix[j][i])
            arr.reverse()
            arr_2.append(arr)
        for i in range(1,len(matrix)//2):
            arr = []
            for j in range(len(matrix)//2-i,len(matrix)//2+i):
                arr.append(matrix[j][len(matrix)//2+i])
            arr.reverse()
            arr_2.append(arr)
        arr_3 = []
        for i in range(len(matrix)//2):
            arr_3.append([matrix[i][i], matrix[i][len(matrix)-i-1], matrix[len(matrix)-i-1][len(matrix)-i-1], matrix[len(matrix)-1-i][i]])
        for i in range(len(matrix)//2):
            matrix[i][i], matrix[i][len(matrix)-i-1], matrix[len(matrix)-i-1][len(matrix)-i-1], matrix[len(matrix)-1-i][i] = arr_3[i][-1], arr_3[i][0], arr_3[i][1], arr_3[i][2]
        for i in range(len(matrix)//2):
            for j in range(len(matrix)-2-2*i):
                matrix[i][j+i+1] = arr_2[i][j]
                matrix[len(matrix)-1-i][j+i+1] = arr_2[len(arr_2)-1-i][j]
                matrix[j+1+i][i] = arr_1[len(arr_1)-1-i][j]
                matrix[j+1+i][len(matrix)-1-i] = arr_1[i][j]    
     else:
         arr_1 = []
         for i in range(len(matrix)//2):
             arr_1.append(matrix[i][i+1:len(matrix)-1-i])
         for i in range(1,len(matrix)//2+1):
             arr_1.append(matrix[len(matrix)//2+i][len(matrix)//2-i+1:len(matrix)//2+i])
         arr_2 = []
         for i in range(len(matrix)//2):
             arr = []
             for j in range(i+1,len(matrix)-1-i):
                 arr.append(matrix[j][i])
             arr.reverse()
             arr_2.append(arr)
         for i in range(1,len(matrix)//2+1):
             arr = []
             for j in range(len(matrix)//2-i+1,len(matrix)//2+i):
                 arr.append(matrix[j][len(matrix)//2+i])
             arr.reverse()
             arr_2.append(arr)
         arr_3 = []
         for i in range(len(matrix)//2):
             arr_3.append([matrix[i][i], matrix[i][len(matrix)-i-1], matrix[len(matrix)-i-1][len(matrix)-i-1], matrix[len(matrix)-1-i][i]])
         for i in range(len(matrix)//2):
             matrix[i][i], matrix[i][len(matrix)-i-1], matrix[len(matrix)-i-1][len(matrix)-i-1], matrix[len(matrix)-1-i][i] = arr_3[i][-1], arr_3[i][0], arr_3[i][1], arr_3[i][2]
         for i in range(len(matrix)//2):
             arr_3.append([matrix[i][i], matrix[i][len(matrix)-i-1], matrix[len(matrix)-i-1][len(matrix)-i-1], matrix[len(matrix)-1-i][i]])
         for i in range(len(matrix)//2):
             matrix[i][i], matrix[i][len(matrix)-i-1], matrix[len(matrix)-i-1][len(matrix)-i-1], matrix[len(matrix)-1-i][i] = arr_3[i][-1], arr_3[i][0], arr_3[i][1], arr_3[i][2]
         for i in range(len(matrix)//2):
             for j in range(len(matrix)-2-2*i):
                 matrix[i][j+i+1] = arr_2[i][j]
                 matrix[len(matrix)-1-i][j+i+1] = arr_2[len(arr_2)-1-i][j]
                 matrix[j+1+i][i] = arr_1[len(arr_1)-1-i][j]
                 matrix[j+1+i][len(matrix)-1-i] = arr_1[i][j]

matrix = [[5,1,9,11],[2,4,8,10],[13,3,6,7],[15,14,12,16]]
rotate(matrix)
print(matrix)
matrix = [[1,2,3,4,5],[6,7,8,9,0],[3,4,5,6,7],[10,11,12,13,14],[1,2,3,4,5]]
rotate(matrix)
print(matrix)

