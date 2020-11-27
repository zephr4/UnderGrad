from logic import TruthTable
#help from Jordan Nguyen

a = 'Y'
prop = list()

while(a == 'Y'):
	ans = raw_input('Enter a proposition: ')
	prop.append(ans)
	a = raw_input('Would you like to enter more (Y/N): ')
		
myTable = TruthTable(prop)

#print myTable.table
#print myTable.display()
#print myTable.latex()

test = 0

for b in range(len(myTable.table)):
	for c in range(len(prop)):
		if myTable.table[b][1][c] != 1:
			test = 0
			break
		elif myTable.table[b][1][c] == 1:	
			test = 1
	if test == 1:
		break
		
if test == 1:
	print('Your description is consistent')
else:
	print('Your description is not consistent')
	