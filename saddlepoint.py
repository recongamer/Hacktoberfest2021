#Python program that determine the location of a saddle point of matrix if one exists. 
# An m*n matrix is said to have a saddle point if some entry a[i][j] is the smallest in a row  i and largest value in j.


# Find saddle point function
def saddlepoint(l, x, y):
    boolen = False
    for i in range(x):
       mini = min(l[i])
       maxx = mini
       index = []
       for k in range(y):
           if l[i][k] == mini:
               index.append(k)

       for ind in index:
           flag = 1
           a = i
           b = ind
           for j in range(x):
               if l[j][ind] > maxx:
                   flag=0
                   break
           if flag == 1:
               boolen = True
               print("\n Saddle point at -> (", a+1, ",", b+1, ") \n value -> ", l[a][b])

    if boolen==False:
        print("\n No Saddle point present")


# main function
def main():
    n=int(input("Enter the number of rows:"))
    m=int(input("Enter the number of columns:"))
    print("\n Enter the element of matrix for ")
    matrix=[]
    for i in range(n):
        row=[]
        for j in range(m):
            row.append(int(input()))
        matrix.append(row)
    print("\n\n matrix :-> ")
    for i in range(n):
        print(matrix[i])
    saddlepoint(matrix, n, m)


main()

