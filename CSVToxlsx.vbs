Set args = Wscript.Arguments

For Each sFilename In args
    iErr = ConvertExcelFormat(sFilename)
    ' 0 for normal success
    ' 404 for file not found
    ' 10 for file skipped (or user abort if script returns 10)
Next

WScript.Quit(0)

Function ConvertExcelFormat(srcFile)

    if IsEmpty(srcFile) OR srcFile = "" Then
        WScript.Echo "Error! Please specify at least one source path. Usage: " & WScript.ScriptName & " SourcePath.xls*|csv"
        ConvertExcelFormat = -1
        Exit Function
        'Wscript.Quit
    End If

    Set objFSO = CreateObject("Scripting.FileSystemObject")

    srcExt = objFSO.GetExtensionName(srcFile)

    ' the 6 is the constant for 'CSV' format, 51 is for 'xlsx'
    ' https://msdn.microsoft.com/en-us/vba/excel-vba/articles/xlfileformat-enumeration-excel
    ' https://www.rondebruin.nl/mac/mac020.htm
    Dim outputFormat, srcDest

    If LCase(Mid(srcExt, 1, 2)) = "xl" Then
        outputFormat = 6
        srcDest = "csv"
    Else
        outputFormat = 51
        srcDest = "xlsx"
    End If

    'srcFile = objFSO.GetAbsolutePathName(Wscript.Arguments.Item(0))
    srcFile = objFSO.GetAbsolutePathName(srcFile)
    destFile = Replace(srcFile, srcExt, srcDest)

    Dim oExcel
    Set oExcel = CreateObject("Excel.Application")
    Dim oBook
    Set oBook = oExcel.Workbooks.Open(srcFile)
    ' preserve formatting? https://stackoverflow.com/a/8658845/1037948
    'oBook.Application.Columns("A:J").NumberFormat = "@"
    oBook.SaveAs destFile, outputFormat
    oBook.Close False
    oExcel.Quit
    'WScript.Echo "Conversion complete of '" & srcFile & "' to '" & objFSO.GetFileName(destFile) & "'"

End Function