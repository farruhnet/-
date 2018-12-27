# C-
Projects in C++ Language


## Develop a console application in Visual Studio 2010/2012 that performs the following actions on matrices
### * Addition (by elements)
### * Multiplication (by elements)
### * Calculating the sum of elements
### * Search for the maximum element
### When implementing the use of OpenMP and Intel Cilk Plus. Conduct experimental research on data processing with different implementations (at least 50 launches for each implementation).
### The results of the experiment for each function should be arranged in the form of tables (when conducting experiments, use matrices from 500 × 500 to 2000 × 2000, calculate for two types of data int and double):
### * - perform several implementations, in particular for Intel Cilk Plus using cilk_for, cilk_spawn, extended index notation, etc.
							Results

<!DOCTYPE html>
<html>
	<head>
		<meta charset="UTF-8">
			
		</head>
		<body>
			<b>
				<u>Sheet Name</u> :- Лист1
			</b>
			<hr>
				<table cellspacing=0 border=1>
					<tr>
						<td style=min-width:50px>Function name</td>
						<td style=min-width:50px>threats</td>
						<td style=min-width:50px>500х500</td>
						<td style=min-width:50px></td>
						<td style=min-width:50px>1000х1000</td>
						<td style=min-width:50px></td>
						<td style=min-width:50px>2000х2000</td>
						<td style=min-width:50px></td>
					</tr>
					<tr>
						<td style=min-width:50px></td>
						<td style=min-width:50px></td>
						<td style=min-width:50px>int</td>
						<td style=min-width:50px>double</td>
						<td style=min-width:50px>int</td>
						<td style=min-width:50px>double</td>
						<td style=min-width:50px>int</td>
						<td style=min-width:50px>double</td>
					</tr>
					<tr>
						<td style=min-width:50px>Sum AxB (OMP)</td>
						<td style=min-width:50px>2</td>
						<td style=min-width:50px>0.00160203</td>
						<td style=min-width:50px>0.00160203</td>
						<td style=min-width:50px>0.00451085</td>
						<td style=min-width:50px>0.00531197</td>
						<td style=min-width:50px>0.0115199</td>
						<td style=min-width:50px>0.0181921</td>
					</tr>
					<tr>
						<td style=min-width:50px></td>
						<td style=min-width:50px>3</td>
						<td style=min-width:50px>0.00141593</td>
						<td style=min-width:50px>0.00141593</td>
						<td style=min-width:50px>0.00427716</td>
						<td style=min-width:50px>0.00513422</td>
						<td style=min-width:50px>0.0125739</td>
						<td style=min-width:50px>0.0164016</td>
					</tr>
					<tr>
						<td style=min-width:50px></td>
						<td style=min-width:50px>4</td>
						<td style=min-width:50px>0.00125135</td>
						<td style=min-width:50px>0.00125135</td>
						<td style=min-width:50px>0.0044026</td>
						<td style=min-width:50px>0.00447092</td>
						<td style=min-width:50px>0.0110354</td>
						<td style=min-width:50px>0.0140764</td>
					</tr>
					<tr>
						<td style=min-width:50px>Sum AxB (Cilk)</td>
						<td style=min-width:50px>2</td>
						<td style=min-width:50px>0.00149502</td>
						<td style=min-width:50px>0.00236011</td>
						<td style=min-width:50px>0.00571399</td>
						<td style=min-width:50px>0.00717089</td>
						<td style=min-width:50px>0.0078139</td>
						<td style=min-width:50px>0.0153692</td>
					</tr>
					<tr>
						<td style=min-width:50px></td>
						<td style=min-width:50px>3</td>
						<td style=min-width:50px>0.00156296</td>
						<td style=min-width:50px>0.00184183</td>
						<td style=min-width:50px>0.00607958</td>
						<td style=min-width:50px>0.00641769</td>
						<td style=min-width:50px>0.00763533</td>
						<td style=min-width:50px>0.0149138</td>
					</tr>
					<tr>
						<td style=min-width:50px></td>
						<td style=min-width:50px>4</td>
						<td style=min-width:50px>0.00163638</td>
						<td style=min-width:50px>0.00174205</td>
						<td style=min-width:50px>0.00592709</td>
						<td style=min-width:50px>0.00689861</td>
						<td style=min-width:50px>0.0076055</td>
						<td style=min-width:50px>0.0146764</td>
					</tr>
					<tr>
						<td style=min-width:50px>Sum AxB (Cilk) full index</td>
						<td style=min-width:50px>2</td>
						<td style=min-width:50px>0.00179132</td>
						<td style=min-width:50px>0.00182279</td>
						<td style=min-width:50px>0.0059432</td>
						<td style=min-width:50px>0.00724893</td>
						<td style=min-width:50px>0.00527237</td>
						<td style=min-width:50px>0.0113951</td>
					</tr>
					<tr>
						<td style=min-width:50px></td>
						<td style=min-width:50px>3</td>
						<td style=min-width:50px>0.00141877</td>
						<td style=min-width:50px>0.00146997</td>
						<td style=min-width:50px>0.00576824</td>
						<td style=min-width:50px>0.00583566</td>
						<td style=min-width:50px>0.00425669</td>
						<td style=min-width:50px>0.00791237</td>
					</tr>
					<tr>
						<td style=min-width:50px></td>
						<td style=min-width:50px>4</td>
						<td style=min-width:50px>0.00142529</td>
						<td style=min-width:50px>0.00146614</td>
						<td style=min-width:50px>0.0057297</td>
						<td style=min-width:50px>0.00570003</td>
						<td style=min-width:50px>0.00432243</td>
						<td style=min-width:50px>0.0081165</td>
					</tr>
					<tr>
						<td style=min-width:50px>Mul AxB (OMP)</td>
						<td style=min-width:50px>2</td>
						<td style=min-width:50px>0.00126006</td>
						<td style=min-width:50px>0.00151912</td>
						<td style=min-width:50px>0.00507801</td>
						<td style=min-width:50px>0.0062407</td>
						<td style=min-width:50px>0.0116229</td>
						<td style=min-width:50px>0.0164274</td>
					</tr>
					<tr>
						<td style=min-width:50px></td>
						<td style=min-width:50px>3</td>
						<td style=min-width:50px>0.00137124</td>
						<td style=min-width:50px>0.00175986</td>
						<td style=min-width:50px>0.00516392</td>
						<td style=min-width:50px>0.00524679</td>
						<td style=min-width:50px>0.0125359</td>
						<td style=min-width:50px>0.0164287</td>
					</tr>
					<tr>
						<td style=min-width:50px></td>
						<td style=min-width:50px>4</td>
						<td style=min-width:50px>0.00127942</td>
						<td style=min-width:50px>0.00112585</td>
						<td style=min-width:50px>0.00496434</td>
						<td style=min-width:50px>0.00518333</td>
						<td style=min-width:50px>0.0108739</td>
						<td style=min-width:50px>0.01537</td>
					</tr>
					<tr>
						<td style=min-width:50px>Mul AxB (Cilk)</td>
						<td style=min-width:50px>2</td>
						<td style=min-width:50px>0.00197204</td>
						<td style=min-width:50px>0.00236887</td>
						<td style=min-width:50px>0.00599132</td>
						<td style=min-width:50px>0.00771237</td>
						<td style=min-width:50px>0.00773993</td>
						<td style=min-width:50px>0.0149075</td>
					</tr>
					<tr>
						<td style=min-width:50px></td>
						<td style=min-width:50px>3</td>
						<td style=min-width:50px>0.001586</td>
						<td style=min-width:50px>0.00167582</td>
						<td style=min-width:50px>0.00607757</td>
						<td style=min-width:50px>0.00674732</td>
						<td style=min-width:50px>0.00772152</td>
						<td style=min-width:50px>0.0148264</td>
					</tr>
					<tr>
						<td style=min-width:50px></td>
						<td style=min-width:50px>4</td>
						<td style=min-width:50px>0.00144263</td>
						<td style=min-width:50px>0.00159716</td>
						<td style=min-width:50px>0.0059159</td>
						<td style=min-width:50px>0.0067026</td>
						<td style=min-width:50px>0.00766912</td>
						<td style=min-width:50px>0.0147088</td>
					</tr>
					<tr>
						<td style=min-width:50px>Mul AxB (Cilk) full index</td>
						<td style=min-width:50px>2</td>
						<td style=min-width:50px>0.00126067</td>
						<td style=min-width:50px>0.00132554</td>
						<td style=min-width:50px>0.00520848</td>
						<td style=min-width:50px>0.00771237</td>
						<td style=min-width:50px>0.00556466</td>
						<td style=min-width:50px>0.00940726</td>
					</tr>
					<tr>
						<td style=min-width:50px></td>
						<td style=min-width:50px>3</td>
						<td style=min-width:50px>0.0014593</td>
						<td style=min-width:50px>0.00135872</td>
						<td style=min-width:50px>0.00596881</td>
						<td style=min-width:50px>0.00581322</td>
						<td style=min-width:50px>0.00363914</td>
						<td style=min-width:50px>0.00660101</td>
					</tr>
					<tr>
						<td style=min-width:50px></td>
						<td style=min-width:50px>4</td>
						<td style=min-width:50px>0.00130424</td>
						<td style=min-width:50px>0.00125744</td>
						<td style=min-width:50px>0.0056404</td>
						<td style=min-width:50px>0.00598724</td>
						<td style=min-width:50px>0.00300597</td>
						<td style=min-width:50px>0.00680748</td>
					</tr>
					<tr>
						<td style=min-width:50px>Sum of elements (OMP) </td>
						<td style=min-width:50px>2</td>
						<td style=min-width:50px>0.000687856</td>
						<td style=min-width:50px>0.000873251</td>
						<td style=min-width:50px>0.00257471</td>
						<td style=min-width:50px>0.00296876</td>
						<td style=min-width:50px>0.00234494</td>
						<td style=min-width:50px>0.00461831</td>
					</tr>
					<tr>
						<td style=min-width:50px></td>
						<td style=min-width:50px>3</td>
						<td style=min-width:50px>0.000554141</td>
						<td style=min-width:50px>0.000822518</td>
						<td style=min-width:50px>0.00242023</td>
						<td style=min-width:50px>0.00281345</td>
						<td style=min-width:50px>0.00223986</td>
						<td style=min-width:50px>0.00427576</td>
					</tr>
					<tr>
						<td style=min-width:50px></td>
						<td style=min-width:50px>4</td>
						<td style=min-width:50px>0.000540424</td>
						<td style=min-width:50px>0.000695239</td>
						<td style=min-width:50px>0.00238455</td>
						<td style=min-width:50px>0.00258824</td>
						<td style=min-width:50px>0.00214908</td>
						<td style=min-width:50px>0.00423862</td>
					</tr>
					<tr>
						<td style=min-width:50px>Sum of elements (Cilk) </td>
						<td style=min-width:50px>2</td>
						<td style=min-width:50px>0.00235892</td>
						<td style=min-width:50px>0.00477958</td>
						<td style=min-width:50px>0.00843515</td>
						<td style=min-width:50px>0.00446083</td>
						<td style=min-width:50px>0.00383778</td>
						<td style=min-width:50px>0.0052618</td>
					</tr>
					<tr>
						<td style=min-width:50px></td>
						<td style=min-width:50px>3</td>
						<td style=min-width:50px>0.00170348</td>
						<td style=min-width:50px>0.004371</td>
						<td style=min-width:50px>0.00718385</td>
						<td style=min-width:50px>0.00434175</td>
						<td style=min-width:50px>0.00394917</td>
						<td style=min-width:50px>0.00505721</td>
					</tr>
					<tr>
						<td style=min-width:50px></td>
						<td style=min-width:50px>4</td>
						<td style=min-width:50px>0.00183356</td>
						<td style=min-width:50px>0.00421895</td>
						<td style=min-width:50px>0.00706447</td>
						<td style=min-width:50px>0.00451831</td>
						<td style=min-width:50px>0.00387427</td>
						<td style=min-width:50px>0.00483277</td>
					</tr>
					<tr>
						<td style=min-width:50px>Sum of el (Cilk) full index</td>
						<td style=min-width:50px>2</td>
						<td style=min-width:50px>0.000652303</td>
						<td style=min-width:50px>0.000850219</td>
						<td style=min-width:50px>0.00267276</td>
						<td style=min-width:50px>0.00289216</td>
						<td style=min-width:50px>0.00165034</td>
						<td style=min-width:50px>0.003262</td>
					</tr>
					<tr>
						<td style=min-width:50px></td>
						<td style=min-width:50px>3</td>
						<td style=min-width:50px>0.000663245</td>
						<td style=min-width:50px>0.000696082</td>
						<td style=min-width:50px>0.00267052</td>
						<td style=min-width:50px>0.00284405</td>
						<td style=min-width:50px>0.00102167</td>
						<td style=min-width:50px>0.00183774</td>
					</tr>
					<tr>
						<td style=min-width:50px></td>
						<td style=min-width:50px>4</td>
						<td style=min-width:50px>0.000703768</td>
						<td style=min-width:50px>0.000616659</td>
						<td style=min-width:50px>0.00284438</td>
						<td style=min-width:50px>0.00281923</td>
						<td style=min-width:50px>0.00108136</td>
						<td style=min-width:50px>0.00207036</td>
					</tr>
					<tr>
						<td style=min-width:50px>Max (OMP) </td>
						<td style=min-width:50px>2</td>
						<td style=min-width:50px>0.000794218</td>
						<td style=min-width:50px>0.000953347</td>
						<td style=min-width:50px>0.00405776</td>
						<td style=min-width:50px>0.00314634</td>
						<td style=min-width:50px>0.00276016</td>
						<td style=min-width:50px>0.00446112</td>
					</tr>
					<tr>
						<td style=min-width:50px></td>
						<td style=min-width:50px>3</td>
						<td style=min-width:50px>0.000764579</td>
						<td style=min-width:50px>0.000897945</td>
						<td style=min-width:50px>0.00327224</td>
						<td style=min-width:50px>0.00341819</td>
						<td style=min-width:50px>0.00268556</td>
						<td style=min-width:50px>0.00443801</td>
					</tr>
					<tr>
						<td style=min-width:50px></td>
						<td style=min-width:50px>4</td>
						<td style=min-width:50px>0.000746864</td>
						<td style=min-width:50px>0.000762659</td>
						<td style=min-width:50px>0.00263114</td>
						<td style=min-width:50px>0.00330501</td>
						<td style=min-width:50px>0.0026952</td>
						<td style=min-width:50px>0.00419324</td>
					</tr>
					<tr>
						<td style=min-width:50px>Max (Cilk) </td>
						<td style=min-width:50px>2</td>
						<td style=min-width:50px>0.00253542</td>
						<td style=min-width:50px>0.00206068</td>
						<td style=min-width:50px>0.00850778</td>
						<td style=min-width:50px>0.00839266</td>
						<td style=min-width:50px>0.00174614</td>
						<td style=min-width:50px>0.0116822</td>
					</tr>
					<tr>
						<td style=min-width:50px></td>
						<td style=min-width:50px>3</td>
						<td style=min-width:50px>0.00211653</td>
						<td style=min-width:50px>0.00218855</td>
						<td style=min-width:50px>0.00821212</td>
						<td style=min-width:50px>0.00742239</td>
						<td style=min-width:50px>0.00138059</td>
						<td style=min-width:50px>0.00866081</td>
					</tr>
					<tr>
						<td style=min-width:50px></td>
						<td style=min-width:50px>4</td>
						<td style=min-width:50px>0.00202468</td>
						<td style=min-width:50px>0.00204294</td>
						<td style=min-width:50px>0.00830591</td>
						<td style=min-width:50px>0.00774326</td>
						<td style=min-width:50px>0.00141409</td>
						<td style=min-width:50px>0.0072794</td>
					</tr>
					<tr>
						<td style=min-width:50px>Max (Cilk) full index</td>
						<td style=min-width:50px>2</td>
						<td style=min-width:50px>0.0006701</td>
						<td style=min-width:50px>0.000671721</td>
						<td style=min-width:50px>0.0026613</td>
						<td style=min-width:50px>0.00273533</td>
						<td style=min-width:50px>0.00167932</td>
						<td style=min-width:50px>0.00265713</td>
					</tr>
					<tr>
						<td style=min-width:50px></td>
						<td style=min-width:50px>3</td>
						<td style=min-width:50px>0.000640154</td>
						<td style=min-width:50px>0.000659207</td>
						<td style=min-width:50px>0.00274318</td>
						<td style=min-width:50px>0.00289041</td>
						<td style=min-width:50px>0.00147384</td>
						<td style=min-width:50px>0.00187211</td>
					</tr>
					<tr>
						<td style=min-width:50px></td>
						<td style=min-width:50px>4</td>
						<td style=min-width:50px>0.000630227</td>
						<td style=min-width:50px>0.000646131</td>
						<td style=min-width:50px>0.00268614</td>
						<td style=min-width:50px>0.00269831</td>
						<td style=min-width:50px>0.00111691</td>
						<td style=min-width:50px>0.00239188</td>
					</tr>
				</table>
				<hr>
				</body>
			</html>
