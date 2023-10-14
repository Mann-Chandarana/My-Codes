n = int(input())

student_marks = {}
for i in range(n):
    name,*line = input().split()
    scores = list(map(float,line))
    student_marks[name] = scores

query_name = input()

sum = 0
length = int;

for key,value in student_marks.items():
    if query_name == key:
        for item in value:
            sum+= item
            length = len(value)

Percentage = sum/length

print('%.2f'%Percentage)