function CodeMetrics() {
	 this.metricsArray = {};
	 this.metricsArray.var = new Array();
	 this.metricsArray.fcn = new Array();
	 this.metricsArray.var["rtInf"] = {file: "C:\\Projects\\myProject\\CleanerRepo\\Area_Coverage\\Software\\SourceCode\\AreaCoverage_MBD\\SW\\SRC\\MainControl\\SRC\\RobotControl_ert_rtw\\rt_nonfinite.c",
	size: 8};
	 this.metricsArray.var["rtInfF"] = {file: "C:\\Projects\\myProject\\CleanerRepo\\Area_Coverage\\Software\\SourceCode\\AreaCoverage_MBD\\SW\\SRC\\MainControl\\SRC\\RobotControl_ert_rtw\\rt_nonfinite.c",
	size: 4};
	 this.metricsArray.var["rtMinusInf"] = {file: "C:\\Projects\\myProject\\CleanerRepo\\Area_Coverage\\Software\\SourceCode\\AreaCoverage_MBD\\SW\\SRC\\MainControl\\SRC\\RobotControl_ert_rtw\\rt_nonfinite.c",
	size: 8};
	 this.metricsArray.var["rtMinusInfF"] = {file: "C:\\Projects\\myProject\\CleanerRepo\\Area_Coverage\\Software\\SourceCode\\AreaCoverage_MBD\\SW\\SRC\\MainControl\\SRC\\RobotControl_ert_rtw\\rt_nonfinite.c",
	size: 4};
	 this.metricsArray.var["rtNaN"] = {file: "C:\\Projects\\myProject\\CleanerRepo\\Area_Coverage\\Software\\SourceCode\\AreaCoverage_MBD\\SW\\SRC\\MainControl\\SRC\\RobotControl_ert_rtw\\rt_nonfinite.c",
	size: 8};
	 this.metricsArray.var["rtNaNF"] = {file: "C:\\Projects\\myProject\\CleanerRepo\\Area_Coverage\\Software\\SourceCode\\AreaCoverage_MBD\\SW\\SRC\\MainControl\\SRC\\RobotControl_ert_rtw\\rt_nonfinite.c",
	size: 4};
	 this.metricsArray.fcn["rtGetInf"] = {file: "C:\\Projects\\myProject\\CleanerRepo\\Area_Coverage\\Software\\SourceCode\\AreaCoverage_MBD\\SW\\SRC\\MainControl\\SRC\\RobotControl_ert_rtw\\rtGetInf.c",
	stack: 18,
	stackTotal: 18};
	 this.metricsArray.fcn["rtGetInfF"] = {file: "C:\\Projects\\myProject\\CleanerRepo\\Area_Coverage\\Software\\SourceCode\\AreaCoverage_MBD\\SW\\SRC\\MainControl\\SRC\\RobotControl_ert_rtw\\rtGetInf.c",
	stack: 4,
	stackTotal: 4};
	 this.metricsArray.fcn["rtGetMinusInf"] = {file: "C:\\Projects\\myProject\\CleanerRepo\\Area_Coverage\\Software\\SourceCode\\AreaCoverage_MBD\\SW\\SRC\\MainControl\\SRC\\RobotControl_ert_rtw\\rtGetInf.c",
	stack: 18,
	stackTotal: 18};
	 this.metricsArray.fcn["rtGetMinusInfF"] = {file: "C:\\Projects\\myProject\\CleanerRepo\\Area_Coverage\\Software\\SourceCode\\AreaCoverage_MBD\\SW\\SRC\\MainControl\\SRC\\RobotControl_ert_rtw\\rtGetInf.c",
	stack: 4,
	stackTotal: 4};
	 this.metricsArray.fcn["rtGetNaN"] = {file: "C:\\Projects\\myProject\\CleanerRepo\\Area_Coverage\\Software\\SourceCode\\AreaCoverage_MBD\\SW\\SRC\\MainControl\\SRC\\RobotControl_ert_rtw\\rtGetNaN.c",
	stack: 18,
	stackTotal: 18};
	 this.metricsArray.fcn["rtGetNaNF"] = {file: "C:\\Projects\\myProject\\CleanerRepo\\Area_Coverage\\Software\\SourceCode\\AreaCoverage_MBD\\SW\\SRC\\MainControl\\SRC\\RobotControl_ert_rtw\\rtGetNaN.c",
	stack: 4,
	stackTotal: 4};
	 this.metricsArray.fcn["rtIsInf"] = {file: "C:\\Projects\\myProject\\CleanerRepo\\Area_Coverage\\Software\\SourceCode\\AreaCoverage_MBD\\SW\\SRC\\MainControl\\SRC\\RobotControl_ert_rtw\\rt_nonfinite.c",
	stack: 0,
	stackTotal: 0};
	 this.metricsArray.fcn["rtIsInfF"] = {file: "C:\\Projects\\myProject\\CleanerRepo\\Area_Coverage\\Software\\SourceCode\\AreaCoverage_MBD\\SW\\SRC\\MainControl\\SRC\\RobotControl_ert_rtw\\rt_nonfinite.c",
	stack: 0,
	stackTotal: 0};
	 this.metricsArray.fcn["rtIsNaN"] = {file: "C:\\Projects\\myProject\\CleanerRepo\\Area_Coverage\\Software\\SourceCode\\AreaCoverage_MBD\\SW\\SRC\\MainControl\\SRC\\RobotControl_ert_rtw\\rt_nonfinite.c",
	stack: 0,
	stackTotal: 0};
	 this.metricsArray.fcn["rtIsNaNF"] = {file: "C:\\Projects\\myProject\\CleanerRepo\\Area_Coverage\\Software\\SourceCode\\AreaCoverage_MBD\\SW\\SRC\\MainControl\\SRC\\RobotControl_ert_rtw\\rt_nonfinite.c",
	stack: 0,
	stackTotal: 0};
	 this.metricsArray.fcn["rt_InitInfAndNaN"] = {file: "C:\\Projects\\myProject\\CleanerRepo\\Area_Coverage\\Software\\SourceCode\\AreaCoverage_MBD\\SW\\SRC\\MainControl\\SRC\\RobotControl_ert_rtw\\rt_nonfinite.c",
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
