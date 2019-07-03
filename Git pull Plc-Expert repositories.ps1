# PLC-EXAMPLES
Write-Host -NoNewLine 'Pull PLC-EXPERT Examples : ';
cd plc-examples\
git pull
cd..

# PLC-Hardware support package for Arduino
Write-Host -NoNewLine 'Pull PLC-EXPERT Arduino Hardware : ';
cd plc-expert-arduino-hardware\
git pull
cd..

# PLC-LAB
Write-Host -NoNewLine 'Pull PLC-EXPERT LAB : ';
cd PlcLab\
git pull
cd..

# PLC-LAB
Write-Host -NoNewLine 'Pull PLC-EXPERT Visuino Examples : ';
cd PlcVisuinoExamples\
git pull
cd..

# PLC-WISP
Write-Host -NoNewLine 'Pull PLC-WISP code : ';
cd Plc-Wisp\
git pull
cd..


# END
Write-Host -NoNewLine 'END, Press any key to continue...';
$null = $Host.UI.RawUI.ReadKey('NoEcho,IncludeKeyDown');

