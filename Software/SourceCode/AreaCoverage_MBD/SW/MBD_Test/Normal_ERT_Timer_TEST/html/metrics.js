function CodeMetrics() {
	 this.metricsArray = {};
	 this.metricsArray.var = new Array();
	 this.metricsArray.fcn = new Array();
	 this.metricsArray.var["blinkTest_B"] = {file: "C:\\Projects\\myProject\\CleanerRepo\\Area_Coverage\\Software\\SourceCode\\AreaCoverage_MBD\\SW\\MBD_Test\\blinkTest_ert_rtw\\blinkTest.c",
	size: 1};
	 this.metricsArray.var["blinkTest_DW"] = {file: "C:\\Projects\\myProject\\CleanerRepo\\Area_Coverage\\Software\\SourceCode\\AreaCoverage_MBD\\SW\\MBD_Test\\blinkTest_ert_rtw\\blinkTest.c",
	size: 6};
	 this.metricsArray.var["blinkTest_M_"] = {file: "C:\\Projects\\myProject\\CleanerRepo\\Area_Coverage\\Software\\SourceCode\\AreaCoverage_MBD\\SW\\MBD_Test\\blinkTest_ert_rtw\\blinkTest.c",
	size: 2};
	 this.metricsArray.fcn["blinkTest_Blink"] = {file: "C:\\Projects\\myProject\\CleanerRepo\\Area_Coverage\\Software\\SourceCode\\AreaCoverage_MBD\\SW\\MBD_Test\\blinkTest_ert_rtw\\Blink.c",
	stack: 0,
	stackTotal: 0};
	 this.metricsArray.fcn["blinkTest_initialize"] = {file: "C:\\Projects\\myProject\\CleanerRepo\\Area_Coverage\\Software\\SourceCode\\AreaCoverage_MBD\\SW\\MBD_Test\\blinkTest_ert_rtw\\blinkTest.c",
	stack: 0,
	stackTotal: 0};
	 this.metricsArray.fcn["blinkTest_step"] = {file: "C:\\Projects\\myProject\\CleanerRepo\\Area_Coverage\\Software\\SourceCode\\AreaCoverage_MBD\\SW\\MBD_Test\\blinkTest_ert_rtw\\blinkTest.c",
	stack: 0,
	stackTotal: 0};
	 this.metricsArray.fcn["digitalWrite"] = {file: "C:\\Projects\\myProject\\CleanerRepo\\Area_Coverage\\Software\\SourceCode\\AreaCoverage_MBD\\SW\\MBD_Test\\blinkTest_ert_rtw\\blinkTest.c",
	stack: 0,
	stackTotal: 0};
	 this.getMetrics = function(token) { 
		 var data;
		 data = this.metricsArray.var[token];
		 if (!data) {
			 data = this.metricsArray.fcn[token];
			 if (data) data.type = "fcn";
		 } else { 
			 data.type = "var";
		 }
	 return data;}
}
	 CodeMetrics.instance = new CodeMetrics();
