#Recieved help from roommate
from logic import TruthTable

prop1 = raw_input("Enter the first proposition statement: ")
prop2 = raw_input("Enter the second proposition statement: ")

myTable1 = TruthTable(['p','q'], [prop1])
myTable2 = TruthTable(['p','q'], [prop2])

print myTable1.table
print myTable2.table

if (myTable1.table == myTable2.table):
	print("The proposition are equivalent")
else:
	print("The proposition are not equivalent")