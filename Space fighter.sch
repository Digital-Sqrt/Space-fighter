EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
Wire Wire Line
	3175 2400 3425 2400
Wire Wire Line
	3175 2300 3425 2300
Wire Wire Line
	4025 2400 4300 2400
Wire Wire Line
	4025 2300 4300 2300
Wire Wire Line
	4900 2400 5200 2400
Wire Wire Line
	4900 2300 5200 2300
Wire Wire Line
	5800 2400 6200 2400
$Comp
L power:+5V #PWR024
U 1 1 5FFFD214
P 5500 2100
F 0 "#PWR024" H 5500 1950 50  0001 C CNN
F 1 "+5V" H 5515 2273 50  0000 C CNN
F 2 "" H 5500 2100 50  0001 C CNN
F 3 "" H 5500 2100 50  0001 C CNN
	1    5500 2100
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR032
U 1 1 5FFFD20A
P 5500 2700
F 0 "#PWR032" H 5500 2450 50  0001 C CNN
F 1 "GND" H 5505 2527 50  0000 C CNN
F 2 "" H 5500 2700 50  0001 C CNN
F 3 "" H 5500 2700 50  0001 C CNN
	1    5500 2700
	1    0    0    -1  
$EndComp
$Comp
L power:+5V #PWR023
U 1 1 5FFFBF37
P 4600 2100
F 0 "#PWR023" H 4600 1950 50  0001 C CNN
F 1 "+5V" H 4615 2273 50  0000 C CNN
F 2 "" H 4600 2100 50  0001 C CNN
F 3 "" H 4600 2100 50  0001 C CNN
	1    4600 2100
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR031
U 1 1 5FFFBF2D
P 4600 2700
F 0 "#PWR031" H 4600 2450 50  0001 C CNN
F 1 "GND" H 4605 2527 50  0000 C CNN
F 2 "" H 4600 2700 50  0001 C CNN
F 3 "" H 4600 2700 50  0001 C CNN
	1    4600 2700
	1    0    0    -1  
$EndComp
$Comp
L power:+5V #PWR022
U 1 1 5FFFB08E
P 3725 2100
F 0 "#PWR022" H 3725 1950 50  0001 C CNN
F 1 "+5V" H 3740 2273 50  0000 C CNN
F 2 "" H 3725 2100 50  0001 C CNN
F 3 "" H 3725 2100 50  0001 C CNN
	1    3725 2100
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR030
U 1 1 5FFFB084
P 3725 2700
F 0 "#PWR030" H 3725 2450 50  0001 C CNN
F 1 "GND" H 3730 2527 50  0000 C CNN
F 2 "" H 3725 2700 50  0001 C CNN
F 3 "" H 3725 2700 50  0001 C CNN
	1    3725 2700
	1    0    0    -1  
$EndComp
Wire Wire Line
	2075 1875 2075 1775
$Comp
L power:+5V #PWR05
U 1 1 5FFFA7A4
P 1700 1600
F 0 "#PWR05" H 1700 1450 50  0001 C CNN
F 1 "+5V" H 1715 1773 50  0000 C CNN
F 2 "" H 1700 1600 50  0001 C CNN
F 3 "" H 1700 1600 50  0001 C CNN
	1    1700 1600
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR03
U 1 1 5FFF98C6
P 2175 1775
F 0 "#PWR03" H 2175 1525 50  0001 C CNN
F 1 "GND" H 2180 1602 50  0000 C CNN
F 2 "" H 2175 1775 50  0001 C CNN
F 3 "" H 2175 1775 50  0001 C CNN
	1    2175 1775
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR013
U 1 1 5FFEACF6
P 2875 1625
F 0 "#PWR013" H 2875 1375 50  0001 C CNN
F 1 "GND" H 2880 1452 50  0000 C CNN
F 2 "" H 2875 1625 50  0001 C CNN
F 3 "" H 2875 1625 50  0001 C CNN
	1    2875 1625
	1    0    0    -1  
$EndComp
$Comp
L power:+5V #PWR04
U 1 1 5FFEA918
P 2875 1425
F 0 "#PWR04" H 2875 1275 50  0001 C CNN
F 1 "+5V" H 2890 1598 50  0000 C CNN
F 2 "" H 2875 1425 50  0001 C CNN
F 3 "" H 2875 1425 50  0001 C CNN
	1    2875 1425
	1    0    0    -1  
$EndComp
$Comp
L Device:C_Small C1
U 1 1 5FFEA22E
P 2875 1525
F 0 "C1" H 2967 1571 50  0000 L CNN
F 1 ".1uF" H 2967 1480 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603" H 2875 1525 50  0001 C CNN
F 3 "https://product.tdk.com/info/en/catalog/datasheets/mlcc_commercial_general_en.pdf" H 2875 1525 50  0001 C CNN
F 4 "C0603X5R1A104K030BC" H 2875 1525 50  0001 C CNN "Manufacturer Number"
F 5 "Digi-Key" H 2875 1525 50  0001 C CNN "Supplier"
F 6 "445-7318-1-ND" H 2875 1525 50  0001 C CNN "Supplier Part No"
F 7 "https://www.digikey.com/en/products/detail/tdk-corporation/C0603X5R1A104K030BC/2732753" H 2875 1525 50  0001 C CNN "Supplier Link"
F 8 "TDK Corporation" H 2875 1525 50  0001 C CNN "Manufacturer"
	1    2875 1525
	1    0    0    -1  
$EndComp
$Comp
L power:+5V #PWR021
U 1 1 5FFE8CD4
P 2875 2100
F 0 "#PWR021" H 2875 1950 50  0001 C CNN
F 1 "+5V" H 2890 2273 50  0000 C CNN
F 2 "" H 2875 2100 50  0001 C CNN
F 3 "" H 2875 2100 50  0001 C CNN
	1    2875 2100
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR029
U 1 1 5FFE86B3
P 2875 2700
F 0 "#PWR029" H 2875 2450 50  0001 C CNN
F 1 "GND" H 2880 2527 50  0000 C CNN
F 2 "" H 2875 2700 50  0001 C CNN
F 3 "" H 2875 2700 50  0001 C CNN
	1    2875 2700
	1    0    0    -1  
$EndComp
$Comp
L LED:APA102-2020 D1
U 1 1 5FFE676D
P 2875 2400
F 0 "D1" H 2725 2675 50  0000 C CNN
F 1 "APA102-2020" H 3200 2125 50  0000 C CNN
F 2 "MyLib:APA102-2020" H 2925 2100 50  0001 L TNN
F 3 "http://www.led-color.com/upload/201604/APA102-2020%20SMD%20LED.pdf" H 2975 2025 50  0001 L TNN
F 4 "APA102-2020 Super LED" H 2875 2400 50  0001 C CNN "Manufacturer Number"
F 5 "Digi-Key" H 2875 2400 50  0001 C CNN "Supplier"
F 6 "1528-1826-ND" H 2875 2400 50  0001 C CNN "Supplier Part No"
F 7 "https://www.digikey.com/en/products/detail/adafruit-industries-llc/3341/6578337" H 2875 2400 50  0001 C CNN "Supplier Link"
F 8 "Led-Color" H 2875 2400 50  0001 C CNN "Manufacturer"
F 9 "4000" H 2875 2400 50  0001 C CNN "Parts Per Reel"
F 10 "https://www.aliexpress.com/item/32856952551.html?spm=a2g0o.productlist.0.0.47832945cWYrZG&algo_pvid=0fca5305-45cd-4c6a-b7af-9f9252951f5f&algo_expid=0fca5305-45cd-4c6a-b7af-9f9252951f5f-10&btsid=0bb0623a16102918867917742eee6c&ws_ab_test=searchweb0_0,searchweb201602_,searchweb201603_" H 2875 2400 50  0001 C CNN "CPN"
	1    2875 2400
	1    0    0    -1  
$EndComp
$Comp
L LED:APA102-2020 D2
U 1 1 60086CED
P 3725 2400
F 0 "D2" H 3575 2675 50  0000 C CNN
F 1 "APA102-2020" H 4050 2125 50  0000 C CNN
F 2 "MyLib:APA102-2020" H 3775 2100 50  0001 L TNN
F 3 "http://www.led-color.com/upload/201604/APA102-2020%20SMD%20LED.pdf" H 3825 2025 50  0001 L TNN
F 4 "APA102-2020 Super LED" H 3725 2400 50  0001 C CNN "Manufacturer Number"
F 5 "Digi-Key" H 3725 2400 50  0001 C CNN "Supplier"
F 6 "1528-1826-ND" H 3725 2400 50  0001 C CNN "Supplier Part No"
F 7 "https://www.digikey.com/en/products/detail/adafruit-industries-llc/3341/6578337" H 3725 2400 50  0001 C CNN "Supplier Link"
F 8 "Led-Color" H 3725 2400 50  0001 C CNN "Manufacturer"
F 9 "4000" H 3725 2400 50  0001 C CNN "Parts Per Reel"
F 10 "https://www.aliexpress.com/item/32856952551.html?spm=a2g0o.productlist.0.0.47832945cWYrZG&algo_pvid=0fca5305-45cd-4c6a-b7af-9f9252951f5f&algo_expid=0fca5305-45cd-4c6a-b7af-9f9252951f5f-10&btsid=0bb0623a16102918867917742eee6c&ws_ab_test=searchweb0_0,searchweb201602_,searchweb201603_" H 3725 2400 50  0001 C CNN "CPN"
	1    3725 2400
	1    0    0    -1  
$EndComp
$Comp
L LED:APA102-2020 D3
U 1 1 60087494
P 4600 2400
F 0 "D3" H 4450 2675 50  0000 C CNN
F 1 "APA102-2020" H 4925 2125 50  0000 C CNN
F 2 "MyLib:APA102-2020" H 4650 2100 50  0001 L TNN
F 3 "http://www.led-color.com/upload/201604/APA102-2020%20SMD%20LED.pdf" H 4700 2025 50  0001 L TNN
F 4 "APA102-2020 Super LED" H 4600 2400 50  0001 C CNN "Manufacturer Number"
F 5 "Digi-Key" H 4600 2400 50  0001 C CNN "Supplier"
F 6 "1528-1826-ND" H 4600 2400 50  0001 C CNN "Supplier Part No"
F 7 "https://www.digikey.com/en/products/detail/adafruit-industries-llc/3341/6578337" H 4600 2400 50  0001 C CNN "Supplier Link"
F 8 "Led-Color" H 4600 2400 50  0001 C CNN "Manufacturer"
F 9 "4000" H 4600 2400 50  0001 C CNN "Parts Per Reel"
F 10 "https://www.aliexpress.com/item/32856952551.html?spm=a2g0o.productlist.0.0.47832945cWYrZG&algo_pvid=0fca5305-45cd-4c6a-b7af-9f9252951f5f&algo_expid=0fca5305-45cd-4c6a-b7af-9f9252951f5f-10&btsid=0bb0623a16102918867917742eee6c&ws_ab_test=searchweb0_0,searchweb201602_,searchweb201603_" H 4600 2400 50  0001 C CNN "CPN"
	1    4600 2400
	1    0    0    -1  
$EndComp
$Comp
L LED:APA102-2020 D4
U 1 1 60088061
P 5500 2400
F 0 "D4" H 5350 2675 50  0000 C CNN
F 1 "APA102-2020" H 5825 2125 50  0000 C CNN
F 2 "MyLib:APA102-2020" H 5550 2100 50  0001 L TNN
F 3 "http://www.led-color.com/upload/201604/APA102-2020%20SMD%20LED.pdf" H 5600 2025 50  0001 L TNN
F 4 "APA102-2020 Super LED" H 5500 2400 50  0001 C CNN "Manufacturer Number"
F 5 "Digi-Key" H 5500 2400 50  0001 C CNN "Supplier"
F 6 "1528-1826-ND" H 5500 2400 50  0001 C CNN "Supplier Part No"
F 7 "https://www.digikey.com/en/products/detail/adafruit-industries-llc/3341/6578337" H 5500 2400 50  0001 C CNN "Supplier Link"
F 8 "Led-Color" H 5500 2400 50  0001 C CNN "Manufacturer"
F 9 "4000" H 5500 2400 50  0001 C CNN "Parts Per Reel"
F 10 "https://www.aliexpress.com/item/32856952551.html?spm=a2g0o.productlist.0.0.47832945cWYrZG&algo_pvid=0fca5305-45cd-4c6a-b7af-9f9252951f5f&algo_expid=0fca5305-45cd-4c6a-b7af-9f9252951f5f-10&btsid=0bb0623a16102918867917742eee6c&ws_ab_test=searchweb0_0,searchweb201602_,searchweb201603_" H 5500 2400 50  0001 C CNN "CPN"
	1    5500 2400
	1    0    0    -1  
$EndComp
Wire Wire Line
	1700 1600 1700 1875
Wire Wire Line
	2425 1775 2425 2300
Wire Wire Line
	6200 1800 6200 2400
Wire Wire Line
	6075 1800 6075 2300
$Comp
L power:GND #PWR012
U 1 1 600B38C2
P 3725 1625
F 0 "#PWR012" H 3725 1375 50  0001 C CNN
F 1 "GND" H 3730 1452 50  0000 C CNN
F 2 "" H 3725 1625 50  0001 C CNN
F 3 "" H 3725 1625 50  0001 C CNN
	1    3725 1625
	1    0    0    -1  
$EndComp
$Comp
L power:+5V #PWR01
U 1 1 600B38CC
P 3725 1425
F 0 "#PWR01" H 3725 1275 50  0001 C CNN
F 1 "+5V" H 3740 1598 50  0000 C CNN
F 2 "" H 3725 1425 50  0001 C CNN
F 3 "" H 3725 1425 50  0001 C CNN
	1    3725 1425
	1    0    0    -1  
$EndComp
$Comp
L Device:C_Small C2
U 1 1 600B38DB
P 3725 1525
F 0 "C2" H 3817 1571 50  0000 L CNN
F 1 ".1uF" H 3817 1480 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603" H 3725 1525 50  0001 C CNN
F 3 "https://product.tdk.com/info/en/catalog/datasheets/mlcc_commercial_general_en.pdf" H 3725 1525 50  0001 C CNN
F 4 "C0603X5R1A104K030BC" H 3725 1525 50  0001 C CNN "Manufacturer Number"
F 5 "Digi-Key" H 3725 1525 50  0001 C CNN "Supplier"
F 6 "445-7318-1-ND" H 3725 1525 50  0001 C CNN "Supplier Part No"
F 7 "https://www.digikey.com/en/products/detail/tdk-corporation/C0603X5R1A104K030BC/2732753" H 3725 1525 50  0001 C CNN "Supplier Link"
F 8 "TDK Corporation" H 3725 1525 50  0001 C CNN "Manufacturer"
	1    3725 1525
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR014
U 1 1 600B4AF9
P 4650 1625
F 0 "#PWR014" H 4650 1375 50  0001 C CNN
F 1 "GND" H 4655 1452 50  0000 C CNN
F 2 "" H 4650 1625 50  0001 C CNN
F 3 "" H 4650 1625 50  0001 C CNN
	1    4650 1625
	1    0    0    -1  
$EndComp
$Comp
L power:+5V #PWR02
U 1 1 600B4B03
P 4650 1425
F 0 "#PWR02" H 4650 1275 50  0001 C CNN
F 1 "+5V" H 4665 1598 50  0000 C CNN
F 2 "" H 4650 1425 50  0001 C CNN
F 3 "" H 4650 1425 50  0001 C CNN
	1    4650 1425
	1    0    0    -1  
$EndComp
$Comp
L Device:C_Small C3
U 1 1 600B4B12
P 4650 1525
F 0 "C3" H 4742 1571 50  0000 L CNN
F 1 ".1uF" H 4742 1480 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603" H 4650 1525 50  0001 C CNN
F 3 "https://product.tdk.com/info/en/catalog/datasheets/mlcc_commercial_general_en.pdf" H 4650 1525 50  0001 C CNN
F 4 "C0603X5R1A104K030BC" H 4650 1525 50  0001 C CNN "Manufacturer Number"
F 5 "Digi-Key" H 4650 1525 50  0001 C CNN "Supplier"
F 6 "445-7318-1-ND" H 4650 1525 50  0001 C CNN "Supplier Part No"
F 7 "https://www.digikey.com/en/products/detail/tdk-corporation/C0603X5R1A104K030BC/2732753" H 4650 1525 50  0001 C CNN "Supplier Link"
F 8 "TDK Corporation" H 4650 1525 50  0001 C CNN "Manufacturer"
	1    4650 1525
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR015
U 1 1 600B4B1C
P 5500 1625
F 0 "#PWR015" H 5500 1375 50  0001 C CNN
F 1 "GND" H 5505 1452 50  0000 C CNN
F 2 "" H 5500 1625 50  0001 C CNN
F 3 "" H 5500 1625 50  0001 C CNN
	1    5500 1625
	1    0    0    -1  
$EndComp
$Comp
L power:+5V #PWR06
U 1 1 600B4B26
P 5500 1425
F 0 "#PWR06" H 5500 1275 50  0001 C CNN
F 1 "+5V" H 5515 1598 50  0000 C CNN
F 2 "" H 5500 1425 50  0001 C CNN
F 3 "" H 5500 1425 50  0001 C CNN
	1    5500 1425
	1    0    0    -1  
$EndComp
$Comp
L Device:C_Small C4
U 1 1 600B4B35
P 5500 1525
F 0 "C4" H 5592 1571 50  0000 L CNN
F 1 ".1uF" H 5592 1480 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603" H 5500 1525 50  0001 C CNN
F 3 "https://product.tdk.com/info/en/catalog/datasheets/mlcc_commercial_general_en.pdf" H 5500 1525 50  0001 C CNN
F 4 "C0603X5R1A104K030BC" H 5500 1525 50  0001 C CNN "Manufacturer Number"
F 5 "Digi-Key" H 5500 1525 50  0001 C CNN "Supplier"
F 6 "445-7318-1-ND" H 5500 1525 50  0001 C CNN "Supplier Part No"
F 7 "https://www.digikey.com/en/products/detail/tdk-corporation/C0603X5R1A104K030BC/2732753" H 5500 1525 50  0001 C CNN "Supplier Link"
F 8 "TDK Corporation" H 5500 1525 50  0001 C CNN "Manufacturer"
	1    5500 1525
	1    0    0    -1  
$EndComp
Wire Wire Line
	2575 2300 2425 2300
Wire Wire Line
	2300 2400 2575 2400
Wire Wire Line
	3125 5900 3375 5900
Wire Wire Line
	3125 5800 3375 5800
Wire Wire Line
	3975 5900 4250 5900
Wire Wire Line
	3975 5800 4250 5800
Wire Wire Line
	4850 5900 5150 5900
Wire Wire Line
	4850 5800 5150 5800
Wire Wire Line
	5750 5900 6150 5900
Wire Wire Line
	5750 5800 6025 5800
$Comp
L power:+5V #PWR028
U 1 1 600CE641
P 5450 5600
F 0 "#PWR028" H 5450 5450 50  0001 C CNN
F 1 "+5V" H 5465 5773 50  0000 C CNN
F 2 "" H 5450 5600 50  0001 C CNN
F 3 "" H 5450 5600 50  0001 C CNN
	1    5450 5600
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR036
U 1 1 600CE64B
P 5450 6200
F 0 "#PWR036" H 5450 5950 50  0001 C CNN
F 1 "GND" H 5455 6027 50  0000 C CNN
F 2 "" H 5450 6200 50  0001 C CNN
F 3 "" H 5450 6200 50  0001 C CNN
	1    5450 6200
	1    0    0    -1  
$EndComp
$Comp
L power:+5V #PWR027
U 1 1 600CE655
P 4550 5600
F 0 "#PWR027" H 4550 5450 50  0001 C CNN
F 1 "+5V" H 4565 5773 50  0000 C CNN
F 2 "" H 4550 5600 50  0001 C CNN
F 3 "" H 4550 5600 50  0001 C CNN
	1    4550 5600
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR035
U 1 1 600CE65F
P 4550 6200
F 0 "#PWR035" H 4550 5950 50  0001 C CNN
F 1 "GND" H 4555 6027 50  0000 C CNN
F 2 "" H 4550 6200 50  0001 C CNN
F 3 "" H 4550 6200 50  0001 C CNN
	1    4550 6200
	1    0    0    -1  
$EndComp
$Comp
L power:+5V #PWR026
U 1 1 600CE669
P 3675 5600
F 0 "#PWR026" H 3675 5450 50  0001 C CNN
F 1 "+5V" H 3690 5773 50  0000 C CNN
F 2 "" H 3675 5600 50  0001 C CNN
F 3 "" H 3675 5600 50  0001 C CNN
	1    3675 5600
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR034
U 1 1 600CE673
P 3675 6200
F 0 "#PWR034" H 3675 5950 50  0001 C CNN
F 1 "GND" H 3680 6027 50  0000 C CNN
F 2 "" H 3675 6200 50  0001 C CNN
F 3 "" H 3675 6200 50  0001 C CNN
	1    3675 6200
	1    0    0    -1  
$EndComp
Wire Wire Line
	2025 5375 2025 5275
$Comp
L power:+5V #PWR011
U 1 1 600CE67E
P 1725 5100
F 0 "#PWR011" H 1725 4950 50  0001 C CNN
F 1 "+5V" H 1740 5273 50  0000 C CNN
F 2 "" H 1725 5100 50  0001 C CNN
F 3 "" H 1725 5100 50  0001 C CNN
	1    1725 5100
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR016
U 1 1 600CE692
P 2825 5125
F 0 "#PWR016" H 2825 4875 50  0001 C CNN
F 1 "GND" H 2830 4952 50  0000 C CNN
F 2 "" H 2825 5125 50  0001 C CNN
F 3 "" H 2825 5125 50  0001 C CNN
	1    2825 5125
	1    0    0    -1  
$EndComp
$Comp
L power:+5V #PWR07
U 1 1 600CE69C
P 2825 4925
F 0 "#PWR07" H 2825 4775 50  0001 C CNN
F 1 "+5V" H 2840 5098 50  0000 C CNN
F 2 "" H 2825 4925 50  0001 C CNN
F 3 "" H 2825 4925 50  0001 C CNN
	1    2825 4925
	1    0    0    -1  
$EndComp
$Comp
L Device:C_Small C5
U 1 1 600CE6AB
P 2825 5025
F 0 "C5" H 2917 5071 50  0000 L CNN
F 1 ".1uF" H 2917 4980 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603" H 2825 5025 50  0001 C CNN
F 3 "https://product.tdk.com/info/en/catalog/datasheets/mlcc_commercial_general_en.pdf" H 2825 5025 50  0001 C CNN
F 4 "C0603X5R1A104K030BC" H 2825 5025 50  0001 C CNN "Manufacturer Number"
F 5 "Digi-Key" H 2825 5025 50  0001 C CNN "Supplier"
F 6 "445-7318-1-ND" H 2825 5025 50  0001 C CNN "Supplier Part No"
F 7 "https://www.digikey.com/en/products/detail/tdk-corporation/C0603X5R1A104K030BC/2732753" H 2825 5025 50  0001 C CNN "Supplier Link"
F 8 "TDK Corporation" H 2825 5025 50  0001 C CNN "Manufacturer"
	1    2825 5025
	1    0    0    -1  
$EndComp
$Comp
L power:+5V #PWR025
U 1 1 600CE6B5
P 2825 5600
F 0 "#PWR025" H 2825 5450 50  0001 C CNN
F 1 "+5V" H 2840 5773 50  0000 C CNN
F 2 "" H 2825 5600 50  0001 C CNN
F 3 "" H 2825 5600 50  0001 C CNN
	1    2825 5600
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR033
U 1 1 600CE6BF
P 2825 6200
F 0 "#PWR033" H 2825 5950 50  0001 C CNN
F 1 "GND" H 2830 6027 50  0000 C CNN
F 2 "" H 2825 6200 50  0001 C CNN
F 3 "" H 2825 6200 50  0001 C CNN
	1    2825 6200
	1    0    0    -1  
$EndComp
$Comp
L LED:APA102-2020 D5
U 1 1 600CE6D0
P 2825 5900
F 0 "D5" H 2675 6175 50  0000 C CNN
F 1 "APA102-2020" H 3150 5625 50  0000 C CNN
F 2 "MyLib:APA102-2020" H 2875 5600 50  0001 L TNN
F 3 "http://www.led-color.com/upload/201604/APA102-2020%20SMD%20LED.pdf" H 2925 5525 50  0001 L TNN
F 4 "APA102-2020 Super LED" H 2825 5900 50  0001 C CNN "Manufacturer Number"
F 5 "Digi-Key" H 2825 5900 50  0001 C CNN "Supplier"
F 6 "1528-1826-ND" H 2825 5900 50  0001 C CNN "Supplier Part No"
F 7 "https://www.digikey.com/en/products/detail/adafruit-industries-llc/3341/6578337" H 2825 5900 50  0001 C CNN "Supplier Link"
F 8 "Led-Color" H 2825 5900 50  0001 C CNN "Manufacturer"
F 9 "4000" H 2825 5900 50  0001 C CNN "Parts Per Reel"
F 10 "https://www.aliexpress.com/item/32856952551.html?spm=a2g0o.productlist.0.0.47832945cWYrZG&algo_pvid=0fca5305-45cd-4c6a-b7af-9f9252951f5f&algo_expid=0fca5305-45cd-4c6a-b7af-9f9252951f5f-10&btsid=0bb0623a16102918867917742eee6c&ws_ab_test=searchweb0_0,searchweb201602_,searchweb201603_" H 2825 5900 50  0001 C CNN "CPN"
	1    2825 5900
	1    0    0    -1  
$EndComp
$Comp
L LED:APA102-2020 D6
U 1 1 600CE6E1
P 3675 5900
F 0 "D6" H 3525 6175 50  0000 C CNN
F 1 "APA102-2020" H 4000 5625 50  0000 C CNN
F 2 "MyLib:APA102-2020" H 3725 5600 50  0001 L TNN
F 3 "http://www.led-color.com/upload/201604/APA102-2020%20SMD%20LED.pdf" H 3775 5525 50  0001 L TNN
F 4 "APA102-2020 Super LED" H 3675 5900 50  0001 C CNN "Manufacturer Number"
F 5 "Digi-Key" H 3675 5900 50  0001 C CNN "Supplier"
F 6 "1528-1826-ND" H 3675 5900 50  0001 C CNN "Supplier Part No"
F 7 "https://www.digikey.com/en/products/detail/adafruit-industries-llc/3341/6578337" H 3675 5900 50  0001 C CNN "Supplier Link"
F 8 "Led-Color" H 3675 5900 50  0001 C CNN "Manufacturer"
F 9 "4000" H 3675 5900 50  0001 C CNN "Parts Per Reel"
F 10 "https://www.aliexpress.com/item/32856952551.html?spm=a2g0o.productlist.0.0.47832945cWYrZG&algo_pvid=0fca5305-45cd-4c6a-b7af-9f9252951f5f&algo_expid=0fca5305-45cd-4c6a-b7af-9f9252951f5f-10&btsid=0bb0623a16102918867917742eee6c&ws_ab_test=searchweb0_0,searchweb201602_,searchweb201603_" H 3675 5900 50  0001 C CNN "CPN"
	1    3675 5900
	1    0    0    -1  
$EndComp
$Comp
L LED:APA102-2020 D7
U 1 1 600CE6F2
P 4550 5900
F 0 "D7" H 4400 6175 50  0000 C CNN
F 1 "APA102-2020" H 4875 5625 50  0000 C CNN
F 2 "MyLib:APA102-2020" H 4600 5600 50  0001 L TNN
F 3 "http://www.led-color.com/upload/201604/APA102-2020%20SMD%20LED.pdf" H 4650 5525 50  0001 L TNN
F 4 "APA102-2020 Super LED" H 4550 5900 50  0001 C CNN "Manufacturer Number"
F 5 "Digi-Key" H 4550 5900 50  0001 C CNN "Supplier"
F 6 "1528-1826-ND" H 4550 5900 50  0001 C CNN "Supplier Part No"
F 7 "https://www.digikey.com/en/products/detail/adafruit-industries-llc/3341/6578337" H 4550 5900 50  0001 C CNN "Supplier Link"
F 8 "Led-Color" H 4550 5900 50  0001 C CNN "Manufacturer"
F 9 "4000" H 4550 5900 50  0001 C CNN "Parts Per Reel"
F 10 "https://www.aliexpress.com/item/32856952551.html?spm=a2g0o.productlist.0.0.47832945cWYrZG&algo_pvid=0fca5305-45cd-4c6a-b7af-9f9252951f5f&algo_expid=0fca5305-45cd-4c6a-b7af-9f9252951f5f-10&btsid=0bb0623a16102918867917742eee6c&ws_ab_test=searchweb0_0,searchweb201602_,searchweb201603_" H 4550 5900 50  0001 C CNN "CPN"
	1    4550 5900
	1    0    0    -1  
$EndComp
$Comp
L LED:APA102-2020 D8
U 1 1 600CE703
P 5450 5900
F 0 "D8" H 5300 6175 50  0000 C CNN
F 1 "APA102-2020" H 5775 5625 50  0000 C CNN
F 2 "MyLib:APA102-2020" H 5500 5600 50  0001 L TNN
F 3 "http://www.led-color.com/upload/201604/APA102-2020%20SMD%20LED.pdf" H 5550 5525 50  0001 L TNN
F 4 "APA102-2020 Super LED" H 5450 5900 50  0001 C CNN "Manufacturer Number"
F 5 "Digi-Key" H 5450 5900 50  0001 C CNN "Supplier"
F 6 "1528-1826-ND" H 5450 5900 50  0001 C CNN "Supplier Part No"
F 7 "https://www.digikey.com/en/products/detail/adafruit-industries-llc/3341/6578337" H 5450 5900 50  0001 C CNN "Supplier Link"
F 8 "Led-Color" H 5450 5900 50  0001 C CNN "Manufacturer"
F 9 "4000" H 5450 5900 50  0001 C CNN "Parts Per Reel"
F 10 "https://www.aliexpress.com/item/32856952551.html?spm=a2g0o.productlist.0.0.47832945cWYrZG&algo_pvid=0fca5305-45cd-4c6a-b7af-9f9252951f5f&algo_expid=0fca5305-45cd-4c6a-b7af-9f9252951f5f-10&btsid=0bb0623a16102918867917742eee6c&ws_ab_test=searchweb0_0,searchweb201602_,searchweb201603_" H 5450 5900 50  0001 C CNN "CPN"
	1    5450 5900
	1    0    0    -1  
$EndComp
$Comp
L MyComp:6pin_conn J2
U 3 1 600CE717
P 2025 5075
F 0 "J2" H 2350 5075 50  0000 R CNN
F 1 "6pin_conn" V 1947 4987 50  0001 R CNN
F 2 "MyLib:Connector" H 2025 5075 50  0001 C CNN
F 3 "" H 2025 5075 50  0001 C CNN
	3    2025 5075
	0    -1   -1   0   
$EndComp
Wire Wire Line
	1725 5100 1725 5375
Wire Wire Line
	1725 5375 2025 5375
$Comp
L MyComp:6pin_conn J2
U 5 1 600CE739
P 6025 5100
F 0 "J2" H 6350 5100 50  0000 R CNN
F 1 "6pin_conn" V 5947 5012 50  0001 R CNN
F 2 "MyLib:Connector" H 6025 5100 50  0001 C CNN
F 3 "" H 6025 5100 50  0001 C CNN
	5    6025 5100
	0    -1   -1   0   
$EndComp
$Comp
L MyComp:6pin_conn J2
U 6 1 600CE743
P 6150 5100
F 0 "J2" H 6475 5100 50  0000 R CNN
F 1 "6pin_conn" V 6072 5012 50  0001 R CNN
F 2 "MyLib:Connector" H 6150 5100 50  0001 C CNN
F 3 "" H 6150 5100 50  0001 C CNN
	6    6150 5100
	0    -1   -1   0   
$EndComp
Wire Wire Line
	6150 5300 6150 5900
Wire Wire Line
	6025 5300 6025 5800
$Comp
L power:GND #PWR017
U 1 1 600CE74F
P 3675 5125
F 0 "#PWR017" H 3675 4875 50  0001 C CNN
F 1 "GND" H 3680 4952 50  0000 C CNN
F 2 "" H 3675 5125 50  0001 C CNN
F 3 "" H 3675 5125 50  0001 C CNN
	1    3675 5125
	1    0    0    -1  
$EndComp
$Comp
L power:+5V #PWR08
U 1 1 600CE759
P 3675 4925
F 0 "#PWR08" H 3675 4775 50  0001 C CNN
F 1 "+5V" H 3690 5098 50  0000 C CNN
F 2 "" H 3675 4925 50  0001 C CNN
F 3 "" H 3675 4925 50  0001 C CNN
	1    3675 4925
	1    0    0    -1  
$EndComp
$Comp
L Device:C_Small C6
U 1 1 600CE768
P 3675 5025
F 0 "C6" H 3767 5071 50  0000 L CNN
F 1 ".1uF" H 3767 4980 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603" H 3675 5025 50  0001 C CNN
F 3 "https://product.tdk.com/info/en/catalog/datasheets/mlcc_commercial_general_en.pdf" H 3675 5025 50  0001 C CNN
F 4 "C0603X5R1A104K030BC" H 3675 5025 50  0001 C CNN "Manufacturer Number"
F 5 "Digi-Key" H 3675 5025 50  0001 C CNN "Supplier"
F 6 "445-7318-1-ND" H 3675 5025 50  0001 C CNN "Supplier Part No"
F 7 "https://www.digikey.com/en/products/detail/tdk-corporation/C0603X5R1A104K030BC/2732753" H 3675 5025 50  0001 C CNN "Supplier Link"
F 8 "TDK Corporation" H 3675 5025 50  0001 C CNN "Manufacturer"
	1    3675 5025
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR018
U 1 1 600CE772
P 4600 5125
F 0 "#PWR018" H 4600 4875 50  0001 C CNN
F 1 "GND" H 4605 4952 50  0000 C CNN
F 2 "" H 4600 5125 50  0001 C CNN
F 3 "" H 4600 5125 50  0001 C CNN
	1    4600 5125
	1    0    0    -1  
$EndComp
$Comp
L power:+5V #PWR09
U 1 1 600CE77C
P 4600 4925
F 0 "#PWR09" H 4600 4775 50  0001 C CNN
F 1 "+5V" H 4615 5098 50  0000 C CNN
F 2 "" H 4600 4925 50  0001 C CNN
F 3 "" H 4600 4925 50  0001 C CNN
	1    4600 4925
	1    0    0    -1  
$EndComp
$Comp
L Device:C_Small C7
U 1 1 600CE78B
P 4600 5025
F 0 "C7" H 4692 5071 50  0000 L CNN
F 1 ".1uF" H 4692 4980 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603" H 4600 5025 50  0001 C CNN
F 3 "https://product.tdk.com/info/en/catalog/datasheets/mlcc_commercial_general_en.pdf" H 4600 5025 50  0001 C CNN
F 4 "C0603X5R1A104K030BC" H 4600 5025 50  0001 C CNN "Manufacturer Number"
F 5 "Digi-Key" H 4600 5025 50  0001 C CNN "Supplier"
F 6 "445-7318-1-ND" H 4600 5025 50  0001 C CNN "Supplier Part No"
F 7 "https://www.digikey.com/en/products/detail/tdk-corporation/C0603X5R1A104K030BC/2732753" H 4600 5025 50  0001 C CNN "Supplier Link"
F 8 "TDK Corporation" H 4600 5025 50  0001 C CNN "Manufacturer"
	1    4600 5025
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR019
U 1 1 600CE795
P 5450 5125
F 0 "#PWR019" H 5450 4875 50  0001 C CNN
F 1 "GND" H 5455 4952 50  0000 C CNN
F 2 "" H 5450 5125 50  0001 C CNN
F 3 "" H 5450 5125 50  0001 C CNN
	1    5450 5125
	1    0    0    -1  
$EndComp
$Comp
L power:+5V #PWR010
U 1 1 600CE79F
P 5450 4925
F 0 "#PWR010" H 5450 4775 50  0001 C CNN
F 1 "+5V" H 5465 5098 50  0000 C CNN
F 2 "" H 5450 4925 50  0001 C CNN
F 3 "" H 5450 4925 50  0001 C CNN
	1    5450 4925
	1    0    0    -1  
$EndComp
$Comp
L Device:C_Small C8
U 1 1 600CE7AE
P 5450 5025
F 0 "C8" H 5542 5071 50  0000 L CNN
F 1 ".1uF" H 5542 4980 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603" H 5450 5025 50  0001 C CNN
F 3 "https://product.tdk.com/info/en/catalog/datasheets/mlcc_commercial_general_en.pdf" H 5450 5025 50  0001 C CNN
F 4 "C0603X5R1A104K030BC" H 5450 5025 50  0001 C CNN "Manufacturer Number"
F 5 "Digi-Key" H 5450 5025 50  0001 C CNN "Supplier"
F 6 "445-7318-1-ND" H 5450 5025 50  0001 C CNN "Supplier Part No"
F 7 "https://www.digikey.com/en/products/detail/tdk-corporation/C0603X5R1A104K030BC/2732753" H 5450 5025 50  0001 C CNN "Supplier Link"
F 8 "TDK Corporation" H 5450 5025 50  0001 C CNN "Manufacturer"
	1    5450 5025
	1    0    0    -1  
$EndComp
$Comp
L MyComp:1pin_conn J14
U 1 1 601A5126
P 2425 1575
F 0 "J14" H 2675 1575 50  0000 C CNN
F 1 "1pin_conn" H 2392 1674 50  0001 C CNN
F 2 "MyLib:Conn_1_Pin" H 2425 1575 50  0001 C CNN
F 3 "" H 2425 1575 50  0001 C CNN
	1    2425 1575
	0    -1   -1   0   
$EndComp
$Comp
L MyComp:1pin_conn J11
U 1 1 601A64C4
P 2175 1575
F 0 "J11" H 2425 1575 50  0000 C CNN
F 1 "1pin_conn" H 2142 1674 50  0001 C CNN
F 2 "MyLib:Conn_1_Pin" H 2175 1575 50  0001 C CNN
F 3 "" H 2175 1575 50  0001 C CNN
	1    2175 1575
	0    -1   -1   0   
$EndComp
$Comp
L MyComp:1pin_conn J12
U 1 1 601A6A08
P 2075 1575
F 0 "J12" H 2325 1575 50  0000 C CNN
F 1 "1pin_conn" H 2042 1674 50  0001 C CNN
F 2 "MyLib:Conn_1_Pin" H 2075 1575 50  0001 C CNN
F 3 "" H 2075 1575 50  0001 C CNN
	1    2075 1575
	0    -1   -1   0   
$EndComp
$Comp
L MyComp:6pin_conn J7
U 4 1 601D000E
P 1900 3825
F 0 "J7" H 2225 3825 50  0000 R CNN
F 1 "6pin_conn" V 1822 3737 50  0001 R CNN
F 2 "MyLib:Connector" H 1900 3825 50  0001 C CNN
F 3 "" H 1900 3825 50  0001 C CNN
	4    1900 3825
	1    0    0    -1  
$EndComp
$Comp
L MyComp:6pin_conn J10
U 3 1 601D0018
P 1900 3650
F 0 "J10" H 2250 3650 50  0000 R CNN
F 1 "6pin_conn" V 1822 3562 50  0001 R CNN
F 2 "MyLib:Connector" H 1900 3650 50  0001 C CNN
F 3 "" H 1900 3650 50  0001 C CNN
	3    1900 3650
	1    0    0    -1  
$EndComp
$Comp
L MyComp:6pin_conn J7
U 5 1 601D944C
P 3125 3925
F 0 "J7" H 3450 3925 50  0000 R CNN
F 1 "6pin_conn" V 3047 3837 50  0001 R CNN
F 2 "MyLib:Connector" H 3125 3925 50  0001 C CNN
F 3 "" H 3125 3925 50  0001 C CNN
	5    3125 3925
	-1   0    0    -1  
$EndComp
$Comp
L MyComp:6pin_conn J7
U 6 1 601D9456
P 3125 4025
F 0 "J7" H 3450 4025 50  0000 R CNN
F 1 "6pin_conn" V 3047 3937 50  0001 R CNN
F 2 "MyLib:Connector" H 3125 4025 50  0001 C CNN
F 3 "" H 3125 4025 50  0001 C CNN
	6    3125 4025
	-1   0    0    -1  
$EndComp
$Comp
L MyComp:6pin_conn J8
U 4 1 601DDD2F
P 1900 3925
F 0 "J8" H 2225 3925 50  0000 R CNN
F 1 "6pin_conn" V 1822 3837 50  0001 R CNN
F 2 "MyLib:Connector" H 1900 3925 50  0001 C CNN
F 3 "" H 1900 3925 50  0001 C CNN
	4    1900 3925
	1    0    0    -1  
$EndComp
$Comp
L MyComp:6pin_conn J9
U 4 1 601DE00C
P 1900 4025
F 0 "J9" H 2225 4025 50  0000 R CNN
F 1 "6pin_conn" V 1822 3937 50  0001 R CNN
F 2 "MyLib:Connector" H 1900 4025 50  0001 C CNN
F 3 "" H 1900 4025 50  0001 C CNN
	4    1900 4025
	1    0    0    -1  
$EndComp
$Comp
L MyComp:6pin_conn J10
U 4 1 601DE22C
P 1900 4125
F 0 "J10" H 2275 4125 50  0000 R CNN
F 1 "6pin_conn" V 1822 4037 50  0001 R CNN
F 2 "MyLib:Connector" H 1900 4125 50  0001 C CNN
F 3 "" H 1900 4125 50  0001 C CNN
	4    1900 4125
	1    0    0    -1  
$EndComp
Wire Wire Line
	1700 3825 1700 3925
Wire Wire Line
	1700 3925 1700 4025
Connection ~ 1700 3925
$Comp
L power:GND #PWR0103
U 1 1 601EB2CD
P 1700 4150
F 0 "#PWR0103" H 1700 3900 50  0001 C CNN
F 1 "GND" H 1705 3977 50  0000 C CNN
F 2 "" H 1700 4150 50  0001 C CNN
F 3 "" H 1700 4150 50  0001 C CNN
	1    1700 4150
	1    0    0    -1  
$EndComp
$Comp
L MyComp:6pin_conn J9
U 3 1 601EF4CC
P 1900 3550
F 0 "J9" H 2225 3550 50  0000 R CNN
F 1 "6pin_conn" V 1822 3462 50  0001 R CNN
F 2 "MyLib:Connector" H 1900 3550 50  0001 C CNN
F 3 "" H 1900 3550 50  0001 C CNN
	3    1900 3550
	1    0    0    -1  
$EndComp
$Comp
L MyComp:6pin_conn J8
U 3 1 601EF742
P 1900 3450
F 0 "J8" H 2225 3450 50  0000 R CNN
F 1 "6pin_conn" V 1822 3362 50  0001 R CNN
F 2 "MyLib:Connector" H 1900 3450 50  0001 C CNN
F 3 "" H 1900 3450 50  0001 C CNN
	3    1900 3450
	1    0    0    -1  
$EndComp
$Comp
L MyComp:6pin_conn J7
U 3 1 601EF944
P 1900 3350
F 0 "J7" H 2225 3350 50  0000 R CNN
F 1 "6pin_conn" V 1822 3262 50  0001 R CNN
F 2 "MyLib:Connector" H 1900 3350 50  0001 C CNN
F 3 "" H 1900 3350 50  0001 C CNN
	3    1900 3350
	1    0    0    -1  
$EndComp
$Comp
L power:+5V #PWR0104
U 1 1 601EFBE6
P 1700 3300
F 0 "#PWR0104" H 1700 3150 50  0001 C CNN
F 1 "+5V" H 1715 3473 50  0000 C CNN
F 2 "" H 1700 3300 50  0001 C CNN
F 3 "" H 1700 3300 50  0001 C CNN
	1    1700 3300
	1    0    0    -1  
$EndComp
Wire Wire Line
	1700 3350 1700 3450
Wire Wire Line
	1700 3450 1700 3550
Connection ~ 1700 3450
Wire Wire Line
	1700 3550 1700 3650
Connection ~ 1700 3550
$Comp
L MyComp:6pin_conn J8
U 1 1 6020370F
P 3525 3925
F 0 "J8" H 3850 3925 50  0000 R CNN
F 1 "6pin_conn" V 3447 3837 50  0001 R CNN
F 2 "MyLib:Connector" H 3525 3925 50  0001 C CNN
F 3 "" H 3525 3925 50  0001 C CNN
	1    3525 3925
	1    0    0    -1  
$EndComp
$Comp
L MyComp:6pin_conn J8
U 2 1 60203719
P 3525 4025
F 0 "J8" H 3850 4025 50  0000 R CNN
F 1 "6pin_conn" V 3447 3937 50  0001 R CNN
F 2 "MyLib:Connector" H 3525 4025 50  0001 C CNN
F 3 "" H 3525 4025 50  0001 C CNN
	2    3525 4025
	1    0    0    -1  
$EndComp
Text Notes 2625 4175 0    50   ~ 0
Wing 01
$Comp
L MyComp:6pin_conn J8
U 5 1 6020F0CB
P 4225 3925
F 0 "J8" H 4550 3925 50  0000 R CNN
F 1 "6pin_conn" V 4147 3837 50  0001 R CNN
F 2 "MyLib:Connector" H 4225 3925 50  0001 C CNN
F 3 "" H 4225 3925 50  0001 C CNN
	5    4225 3925
	-1   0    0    -1  
$EndComp
$Comp
L MyComp:6pin_conn J8
U 6 1 6020F0D5
P 4225 4025
F 0 "J8" H 4550 4025 50  0000 R CNN
F 1 "6pin_conn" V 4147 3937 50  0001 R CNN
F 2 "MyLib:Connector" H 4225 4025 50  0001 C CNN
F 3 "" H 4225 4025 50  0001 C CNN
	6    4225 4025
	-1   0    0    -1  
$EndComp
$Comp
L MyComp:6pin_conn J9
U 1 1 6020F0DF
P 4625 3925
F 0 "J9" H 4950 3925 50  0000 R CNN
F 1 "6pin_conn" V 4547 3837 50  0001 R CNN
F 2 "MyLib:Connector" H 4625 3925 50  0001 C CNN
F 3 "" H 4625 3925 50  0001 C CNN
	1    4625 3925
	1    0    0    -1  
$EndComp
$Comp
L MyComp:6pin_conn J9
U 2 1 6020F0E9
P 4625 4025
F 0 "J9" H 4950 4025 50  0000 R CNN
F 1 "6pin_conn" V 4547 3937 50  0001 R CNN
F 2 "MyLib:Connector" H 4625 4025 50  0001 C CNN
F 3 "" H 4625 4025 50  0001 C CNN
	2    4625 4025
	1    0    0    -1  
$EndComp
Text Notes 3725 4175 0    50   ~ 0
Wing 02\n
$Comp
L MyComp:6pin_conn J9
U 5 1 60214ABB
P 5300 3925
F 0 "J9" H 5625 3925 50  0000 R CNN
F 1 "6pin_conn" V 5222 3837 50  0001 R CNN
F 2 "MyLib:Connector" H 5300 3925 50  0001 C CNN
F 3 "" H 5300 3925 50  0001 C CNN
	5    5300 3925
	-1   0    0    -1  
$EndComp
$Comp
L MyComp:6pin_conn J9
U 6 1 60214AC5
P 5300 4025
F 0 "J9" H 5625 4025 50  0000 R CNN
F 1 "6pin_conn" V 5222 3937 50  0001 R CNN
F 2 "MyLib:Connector" H 5300 4025 50  0001 C CNN
F 3 "" H 5300 4025 50  0001 C CNN
	6    5300 4025
	-1   0    0    -1  
$EndComp
$Comp
L MyComp:6pin_conn J10
U 1 1 60214ACF
P 5700 3925
F 0 "J10" H 6050 3925 50  0000 R CNN
F 1 "6pin_conn" V 5622 3837 50  0001 R CNN
F 2 "MyLib:Connector" H 5700 3925 50  0001 C CNN
F 3 "" H 5700 3925 50  0001 C CNN
	1    5700 3925
	1    0    0    -1  
$EndComp
$Comp
L MyComp:6pin_conn J10
U 2 1 60214AD9
P 5700 4025
F 0 "J10" H 6050 4025 50  0000 R CNN
F 1 "6pin_conn" V 5622 3937 50  0001 R CNN
F 2 "MyLib:Connector" H 5700 4025 50  0001 C CNN
F 3 "" H 5700 4025 50  0001 C CNN
	2    5700 4025
	1    0    0    -1  
$EndComp
Text Notes 4775 4175 0    50   ~ 0
Wing 03\n
Text Notes 5700 4175 0    50   ~ 0
Wing 04\n
Wire Wire Line
	1700 3350 1700 3300
Connection ~ 1700 3350
Text Notes 2450 3600 0    100  ~ 0
Maine Body and Connector PCB
Wire Notes Line
	1575 1150 6350 1150
Text Notes 1575 1150 0    100  ~ 0
BODY
Wire Notes Line
	1575 4650 6350 4650
Wire Notes Line
	1575 6500 1575 4650
Text Notes 1575 4650 0    100  ~ 0
WING 01-04
Wire Notes Line
	1575 6500 6350 6500
Wire Notes Line
	6350 6500 6350 4650
$Comp
L MyComp:6pin_conn J10
U 6 1 6028F46F
P 5225 3300
F 0 "J10" H 5575 3300 50  0000 R CNN
F 1 "6pin_conn" V 5147 3212 50  0001 R CNN
F 2 "MyLib:Connector" H 5225 3300 50  0001 C CNN
F 3 "" H 5225 3300 50  0001 C CNN
	6    5225 3300
	-1   0    0    -1  
$EndComp
$Comp
L MyComp:6pin_conn J10
U 5 1 6028F479
P 5225 3200
F 0 "J10" H 5575 3200 50  0000 R CNN
F 1 "6pin_conn" V 5147 3112 50  0001 R CNN
F 2 "MyLib:Connector" H 5225 3200 50  0001 C CNN
F 3 "" H 5225 3200 50  0001 C CNN
	5    5225 3200
	-1   0    0    -1  
$EndComp
$Comp
L Device:R_Small_US R1
U 1 1 6029802D
P 5500 3425
F 0 "R1" H 5568 3425 50  0000 L CNN
F 1 "R_Small_US" H 5568 3380 50  0001 L CNN
F 2 "Resistors_SMD:R_0805" H 5500 3425 50  0001 C CNN
F 3 "~" H 5500 3425 50  0001 C CNN
	1    5500 3425
	1    0    0    -1  
$EndComp
$Comp
L Device:R_Small_US R2
U 1 1 602996C7
P 5725 3425
F 0 "R2" H 5793 3425 50  0000 L CNN
F 1 "R_Small_US" H 5793 3380 50  0001 L CNN
F 2 "Resistors_SMD:R_0805" H 5725 3425 50  0001 C CNN
F 3 "~" H 5725 3425 50  0001 C CNN
	1    5725 3425
	1    0    0    -1  
$EndComp
Wire Wire Line
	5425 3300 5500 3300
Wire Wire Line
	5500 3300 5500 3325
Wire Wire Line
	5425 3200 5725 3200
Wire Wire Line
	5725 3200 5725 3325
$Comp
L power:GND #PWR0105
U 1 1 602A8917
P 5500 3600
F 0 "#PWR0105" H 5500 3350 50  0001 C CNN
F 1 "GND" H 5505 3427 50  0000 C CNN
F 2 "" H 5500 3600 50  0001 C CNN
F 3 "" H 5500 3600 50  0001 C CNN
	1    5500 3600
	1    0    0    -1  
$EndComp
Wire Wire Line
	5500 3600 5500 3525
$Comp
L power:GND #PWR0106
U 1 1 602ACB0C
P 5725 3600
F 0 "#PWR0106" H 5725 3350 50  0001 C CNN
F 1 "GND" H 5730 3427 50  0000 C CNN
F 2 "" H 5725 3600 50  0001 C CNN
F 3 "" H 5725 3600 50  0001 C CNN
	1    5725 3600
	1    0    0    -1  
$EndComp
Wire Wire Line
	5725 3525 5725 3600
$Comp
L MyComp:1pin_conn J13
U 1 1 6019FFA1
P 2300 1575
F 0 "J13" H 2550 1575 50  0000 C CNN
F 1 "1pin_conn" H 2267 1674 50  0001 C CNN
F 2 "MyLib:Conn_1_Pin" H 2300 1575 50  0001 C CNN
F 3 "" H 2300 1575 50  0001 C CNN
	1    2300 1575
	0    -1   -1   0   
$EndComp
Wire Wire Line
	1700 1875 2075 1875
$Comp
L MyComp:6pin_conn J7
U 1 1 601D0022
P 6075 1600
F 0 "J7" H 6400 1600 50  0000 R CNN
F 1 "6pin_conn" V 5997 1512 50  0001 R CNN
F 2 "MyLib:Connector" H 6075 1600 50  0001 C CNN
F 3 "" H 6075 1600 50  0001 C CNN
	1    6075 1600
	0    -1   -1   0   
$EndComp
$Comp
L MyComp:6pin_conn J7
U 2 1 601D002C
P 6200 1600
F 0 "J7" H 6525 1600 50  0000 R CNN
F 1 "6pin_conn" V 6122 1512 50  0001 R CNN
F 2 "MyLib:Connector" H 6200 1600 50  0001 C CNN
F 3 "" H 6200 1600 50  0001 C CNN
	2    6200 1600
	0    -1   -1   0   
$EndComp
Wire Wire Line
	2300 1775 2300 2400
$Comp
L Connector:Conn_01x06_Male J99
U 1 1 601FD1D6
P 6675 5625
F 0 "J99" H 6783 6006 50  0001 C CNN
F 1 "Conn_01x06_Male" H 6783 5915 50  0001 C CNN
F 2 "" H 6675 5625 50  0001 C CNN
F 3 "~" H 6675 5625 50  0001 C CNN
	1    6675 5625
	1    0    0    -1  
$EndComp
Text Notes 6650 5325 0    50   ~ 0
Wing Connector\nPin Out
Text GLabel 6975 5425 2    50   Input ~ 0
SDI
Text GLabel 6975 5525 2    50   Input ~ 0
CKI
Text GLabel 6975 5825 2    50   Input ~ 0
SDO
Text GLabel 6975 5925 2    50   Input ~ 0
CKO
$Comp
L power:GND #PWR0101
U 1 1 60202710
P 7325 5825
F 0 "#PWR0101" H 7325 5575 50  0001 C CNN
F 1 "GND" H 7330 5652 50  0000 C CNN
F 2 "" H 7325 5825 50  0001 C CNN
F 3 "" H 7325 5825 50  0001 C CNN
	1    7325 5825
	1    0    0    -1  
$EndComp
$Comp
L power:+5V #PWR0102
U 1 1 60202B00
P 7325 5500
F 0 "#PWR0102" H 7325 5350 50  0001 C CNN
F 1 "+5V" H 7340 5673 50  0000 C CNN
F 2 "" H 7325 5500 50  0001 C CNN
F 3 "" H 7325 5500 50  0001 C CNN
	1    7325 5500
	1    0    0    -1  
$EndComp
Wire Wire Line
	6875 5625 7325 5625
Wire Wire Line
	7325 5625 7325 5500
Wire Wire Line
	6875 5725 7325 5725
Wire Wire Line
	7325 5725 7325 5825
Wire Wire Line
	6875 5425 6975 5425
Wire Wire Line
	6875 5525 6975 5525
Wire Wire Line
	6875 5825 6975 5825
Wire Wire Line
	6875 5925 6975 5925
Text Notes 6600 5450 0    50   ~ 0
A
Text Notes 6600 5550 0    50   ~ 0
B
Text Notes 6600 5650 0    50   ~ 0
C
Text Notes 6600 5750 0    50   ~ 0
D
Text Notes 6600 5850 0    50   ~ 0
E
Text Notes 6600 5950 0    50   ~ 0
F
Wire Notes Line
	1575 4400 6350 4400
Text Notes 5975 1725 1    50   ~ 0
Wing 01
$Comp
L MyComp:6pin_conn J2
U 4 1 600CE70D
P 2125 5075
F 0 "J2" H 2450 5075 50  0000 R CNN
F 1 "6pin_conn" V 2047 4987 50  0001 R CNN
F 2 "MyLib:Connector" H 2125 5075 50  0001 C CNN
F 3 "" H 2125 5075 50  0001 C CNN
	4    2125 5075
	0    -1   -1   0   
$EndComp
$Comp
L power:GND #PWR020
U 1 1 600CE688
P 2125 5275
F 0 "#PWR020" H 2125 5025 50  0001 C CNN
F 1 "GND" H 2130 5102 50  0000 C CNN
F 2 "" H 2125 5275 50  0001 C CNN
F 3 "" H 2125 5275 50  0001 C CNN
	1    2125 5275
	1    0    0    -1  
$EndComp
Wire Wire Line
	2525 5800 2375 5800
Wire Wire Line
	5800 2300 6075 2300
Wire Wire Line
	2250 5900 2525 5900
Wire Wire Line
	2250 5900 2250 5275
Wire Wire Line
	2375 5275 2375 5800
$Comp
L MyComp:6pin_conn J2
U 1 1 600CE72D
P 2375 5075
F 0 "J2" H 2700 5075 50  0000 R CNN
F 1 "6pin_conn" V 2297 4987 50  0001 R CNN
F 2 "MyLib:Connector" H 2375 5075 50  0001 C CNN
F 3 "" H 2375 5075 50  0001 C CNN
	1    2375 5075
	0    -1   -1   0   
$EndComp
$Comp
L MyComp:6pin_conn J2
U 2 1 600CE723
P 2250 5075
F 0 "J2" H 2575 5075 50  0000 R CNN
F 1 "6pin_conn" V 2172 4987 50  0001 R CNN
F 2 "MyLib:Connector" H 2250 5075 50  0001 C CNN
F 3 "" H 2250 5075 50  0001 C CNN
	2    2250 5075
	0    -1   -1   0   
$EndComp
Connection ~ 1700 4025
Wire Wire Line
	1700 4025 1700 4125
Connection ~ 1700 4125
Wire Wire Line
	1700 4125 1700 4150
Wire Notes Line
	6350 1150 6350 4400
Wire Notes Line
	1575 1150 1575 4400
$EndSCHEMATC
