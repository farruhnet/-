
## **A program that implements sorting of a one-dimensional array by different algorithms (in a sequential and parallel implementation):**
### • Bubble (sequential implementation only)
### • Even-odd permutation
### • Shell
### • Quick sorting (qsort)
For each implementation of the array sorting functions, perform a time calculation and form a pivot table. In this case, sorting is performed on the same data set, i.e. the original values of the array are copied into the array intended for sorting.


RESULTS
<!DOCTYPE html>
<html>
	<head>
		<meta charset="UTF-8">
		</head>
		<body>
			<b>
				<u>Sheet Name</u> :- Sheet1
			</b>
			<hr>
				<table cellspacing=0 border=1>
					<tr>
						<td style=min-width:50px>Function Name</td>
						<td style=min-width:50px>Time (Number of data 5000)</td>
						<td style=min-width:50px></td>
						<td style=min-width:50px></td>
						<td style=min-width:50px>Time (Number of data 6000)</td>
						<td style=min-width:50px></td>
						<td style=min-width:50px></td>
						<td style=min-width:50px>Time (Number of data 8000)</td>
						<td style=min-width:50px></td>
						<td style=min-width:50px></td>
						<td style=min-width:50px>Data Number 5000</td>
						<td style=min-width:50px>Data Number 6000</td>
						<td style=min-width:50px>Data Number 8000</td>
					</tr>
					<tr>
						<td style=min-width:50px></td>
						<td style=min-width:50px> 2 Потока</td>
						<td style=min-width:50px>3 потока</td>
						<td style=min-width:50px>4 потока</td>
						<td style=min-width:50px> 2 Потока</td>
						<td style=min-width:50px>3 потока</td>
						<td style=min-width:50px>4 потока</td>
						<td style=min-width:50px> 2 Потока</td>
						<td style=min-width:50px>3 потока</td>
						<td style=min-width:50px>4 потока</td>
						<td style=min-width:50px>1 поток</td>
						<td style=min-width:50px>1 поток</td>
						<td style=min-width:50px>1 поток</td>
					</tr>
					<tr>
						<td style=min-width:50px>Bubble</td>
						<td style=min-width:50px>5.5320000000000001E-2</td>
						<td style=min-width:50px>5.6439999999999997E-2</td>
						<td style=min-width:50px>5.602E-2</td>
						<td style=min-width:50px>7.8923999999999994E-2</td>
						<td style=min-width:50px>8.2199999999999995E-2</td>
						<td style=min-width:50px>8.1729999999999997E-2</td>
						<td style=min-width:50px>0.142045</td>
						<td style=min-width:50px>1.4120000000000001E-2</td>
						<td style=min-width:50px>0.14130000000000001</td>
						<td style=min-width:50px>5.8819999999999997E-2</td>
						<td style=min-width:50px>8.1699999999999995E-2</td>
						<td style=min-width:50px>0.14319999999999999</td>
					</tr>
					<tr>
						<td style=min-width:50px>Bubble_Par_For</td>
						<td style=min-width:50px>4.2700000000000002E-2</td>
						<td style=min-width:50px>3.8100000000000002E-2</td>
						<td style=min-width:50px>3.4840000000000003E-2</td>
						<td style=min-width:50px>6.1058000000000001E-2</td>
						<td style=min-width:50px>5.169E-2</td>
						<td style=min-width:50px>4.5469999999999997E-2</td>
						<td style=min-width:50px>0.1124</td>
						<td style=min-width:50px>9.7780000000000006E-2</td>
						<td style=min-width:50px>9.4200000000000006E-2</td>
						<td style=min-width:50px></td>
						<td style=min-width:50px></td>
						<td style=min-width:50px></td>
					</tr>
					<tr>
						<td style=min-width:50px>Bubble_Par_Shedule_Dynamic</td>
						<td style=min-width:50px>2.8760000000000001E-2</td>
						<td style=min-width:50px>8.2199999999999995E-2</td>
						<td style=min-width:50px>2.3959999999999999E-2</td>
						<td style=min-width:50px>4.0871999999999999E-2</td>
						<td style=min-width:50px>3.6900000000000002E-2</td>
						<td style=min-width:50px>3.4200000000000001E-2</td>
						<td style=min-width:50px>7.4200000000000002E-2</td>
						<td style=min-width:50px>6.5199999999999994E-2</td>
						<td style=min-width:50px>6.4100000000000004E-2</td>
						<td style=min-width:50px></td>
						<td style=min-width:50px></td>
						<td style=min-width:50px></td>
					</tr>
					<tr>
						<td style=min-width:50px>Bubble_Par_Shared</td>
						<td style=min-width:50px>4.7100000000000003E-2</td>
						<td style=min-width:50px>3.5700000000000003E-2</td>
						<td style=min-width:50px>3.5409999999999997E-2</td>
						<td style=min-width:50px>6.1691999999999997E-2</td>
						<td style=min-width:50px>5.9200000000000003E-2</td>
						<td style=min-width:50px>5.1799999999999999E-2</td>
						<td style=min-width:50px>0.1081</td>
						<td style=min-width:50px>0.10549</td>
						<td style=min-width:50px>8.5000000000000006E-2</td>
						<td style=min-width:50px></td>
						<td style=min-width:50px></td>
						<td style=min-width:50px></td>
					</tr>
					<tr>
						<td style=min-width:50px>Shell_Sort</td>
						<td style=min-width:50px>6.9999999999999999E-4</td>
						<td style=min-width:50px>8.7000000000000001E-4</td>
						<td style=min-width:50px>8.5999999999999998E-4</td>
						<td style=min-width:50px>8.0099999999999995E-4</td>
						<td style=min-width:50px>1.1199999999999999E-3</td>
						<td style=min-width:50px>1.1000000000000001E-3</td>
						<td style=min-width:50px>1.1000000000000001E-3</td>
						<td style=min-width:50px>1.2800000000000001E-3</td>
						<td style=min-width:50px>1.5E-3</td>
						<td style=min-width:50px></td>
						<td style=min-width:50px></td>
						<td style=min-width:50px></td>
					</tr>
					<tr>
						<td style=min-width:50px>Shell_Sort(Shared)</td>
						<td style=min-width:50px>4.0000000000000002E-4</td>
						<td style=min-width:50px>5.0000000000000001E-4</td>
						<td style=min-width:50px>4.6799999999999999E-4</td>
						<td style=min-width:50px>7.2199999999999999E-4</td>
						<td style=min-width:50px>5.9999999999999995E-4</td>
						<td style=min-width:50px>5.8599999999999998E-3</td>
						<td style=min-width:50px>7.3999999999999999E-4</td>
						<td style=min-width:50px>7.2000000000000005E-4</td>
						<td style=min-width:50px>6.8999999999999997E-4</td>
						<td style=min-width:50px></td>
						<td style=min-width:50px></td>
						<td style=min-width:50px></td>
					</tr>
					<tr>
						<td style=min-width:50px> QuickSort</td>
						<td style=min-width:50px>5.0000000000000001E-4</td>
						<td style=min-width:50px>5.9999999999999995E-4</td>
						<td style=min-width:50px>4.4999999999999999E-4</td>
						<td style=min-width:50px>6.5700000000000003E-4</td>
						<td style=min-width:50px>8.8900000000000003E-4</td>
						<td style=min-width:50px>8.8000000000000003E-4</td>
						<td style=min-width:50px>8.4000000000000003E-4</td>
						<td style=min-width:50px>9.3099999999999997E-4</td>
						<td style=min-width:50px>1.16E-3</td>
						<td style=min-width:50px></td>
						<td style=min-width:50px></td>
						<td style=min-width:50px></td>
					</tr>
					<tr>
						<td style=min-width:50px>QuickSort(Sec)</td>
						<td style=min-width:50px>3.1890000000000002E-2</td>
						<td style=min-width:50px>3.8999999999999998E-3</td>
						<td style=min-width:50px>4.241E-3</td>
						<td style=min-width:50px>3.571E-3</td>
						<td style=min-width:50px>4.4869999999999997E-3</td>
						<td style=min-width:50px>4.3E-3</td>
						<td style=min-width:50px>4.7000000000000002E-3</td>
						<td style=min-width:50px>5.5999999999999995E-4</td>
						<td style=min-width:50px>4.7999999999999996E-3</td>
						<td style=min-width:50px></td>
						<td style=min-width:50px></td>
						<td style=min-width:50px></td>
					</tr>
					<tr>
						<td style=min-width:50px>OddEvenSort</td>
						<td style=min-width:50px>6.336E-2</td>
						<td style=min-width:50px>5.8799999999999998E-2</td>
						<td style=min-width:50px>5.8400000000000001E-2</td>
						<td style=min-width:50px>8.4018999999999996E-2</td>
						<td style=min-width:50px>8.5699999999999998E-2</td>
						<td style=min-width:50px>8.43E-2</td>
						<td style=min-width:50px>0.1457</td>
						<td style=min-width:50px>0.14560000000000001</td>
						<td style=min-width:50px>0.14399999999999999</td>
						<td style=min-width:50px></td>
						<td style=min-width:50px></td>
						<td style=min-width:50px></td>
					</tr>
					<tr>
						<td style=min-width:50px>OddEvenSortParal(Shared)</td>
						<td style=min-width:50px>3.8011000000000003E-2</td>
						<td style=min-width:50px>3.0417E-2</td>
						<td style=min-width:50px>2.7689999999999999E-2</td>
						<td style=min-width:50px>4.6654000000000001E-2</td>
						<td style=min-width:50px>4.5499999999999999E-2</td>
						<td style=min-width:50px>3.9899999999999998E-2</td>
						<td style=min-width:50px>7.9899999999999999E-2</td>
						<td style=min-width:50px>7.8700000000000006E-2</td>
						<td style=min-width:50px>6.7799999999999999E-2</td>
						<td style=min-width:50px></td>
						<td style=min-width:50px></td>
						<td style=min-width:50px></td>
					</tr>
				</table>
				<hr>
				</body>
			</html>
