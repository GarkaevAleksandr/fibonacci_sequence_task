import matplotlib.pyplot as plt
import numpy as np, array

def readFubFile(*fileName):

	dataDict = {}
		
	for i in fileName:
		file = open(i, "r")
		file = file.readlines()

		value = []
		time = []

		for data in file:
			data = data.split(" ")
			value.append(data[0])
			time.append(data[1])

		dataDict[i[0]] = {"value": value, "time": time}
	
	return dataDict

def graphics(data):
	
	plt.figure(1)
	plt.plot(np.array(data["1"]["time"]), np.array(data["1"]["value"]), "-o")
	plt.title ("Fibonacci 50")
	plt.xlabel ("time")
	plt.ylabel ("value")
	plt.grid()

	plt.figure(2)
	plt.plot(np.array(data["2"]["time"]), np.array(data["2"]["value"]), "-o")
	plt.title ("Fibonacci 100"), "-o"
	plt.xlabel ("time")
	plt.ylabel ("value")
	plt.grid()

	plt.figure(3)
	plt.plot(np.array(data["3"]["time"]), np.array(data["3"]["value"]), "-o")
	plt.title ("Recursive Fibonacci")
	plt.xlabel ("time")
	plt.ylabel ("value")
	plt.grid()

	plt.show()


if __name__ == "__main__":
	
	graphics(readFubFile("1.txt", "2.txt", "3.txt"))
	
	
