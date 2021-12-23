
# PLC-Hardware support package for Arduino
Write-Host -NoNewLine 'Pull PLC-X Arduino Hardware : ';
git pull

# END
Write-Host -NoNewLine 'END, Press any key to continue...';
$null = $Host.UI.RawUI.ReadKey('NoEcho,IncludeKeyDown');

