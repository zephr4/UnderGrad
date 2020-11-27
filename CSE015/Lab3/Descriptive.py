from logic import TruthTable
#help from Jordan Nguyen

a = 'Y'
prop = list()

while(a == 'Y'):
	ans = raw_input('Enter a proposition: ')
	prop.append(ans)
	a = raw_input('Would you like to enter more (Y/N): ')
		
myTable = TruthTable(prop)

print('Your program uses propositional variables ' + str(myTable.vars))

var = list()
for a in range(len(myTable.vars)):
	var.append(raw_input('Enter meaning of ' + str(myTable.vars[a]) + ': '))

#print myTable.table
#print myTable.display();

test = 0
var2 = list()
for i in range(len(myTable.table)):
	for j in range(len(prop)):
		if myTable.table[i][1][j] != 1:
			test = 0
			break
		elif myTable.table[i][1][j] == 1:	
			test = 1
	if test == 1:
		var2.append(i)
		
if var2:
	print('Your description is consistent when: \n')
	for b in range(len(var2)):
		for c in range(len(myTable.vars)):
			if myTable.table[var2[b]][0][c] == 1:
				print('It is the case that ' + str(var[c])) 	
			else:
				print('It is not the case that ' + str(var[c]))
else:
	print('Your description is not consistent')
	