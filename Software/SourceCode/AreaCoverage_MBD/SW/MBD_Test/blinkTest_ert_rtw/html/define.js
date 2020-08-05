function CodeDefine() { 
this.def = new Array();
this.def["rt_OneStep"] = {file: "ert_main_c.html",line:33,type:"fcn"};
this.def["main"] = {file: "ert_main_c.html",line:70,type:"fcn"};
this.def["blinkTest_B"] = {file: "blinkTest_c.html",line:20,type:"var"};
this.def["blinkTest_DW"] = {file: "blinkTest_c.html",line:23,type:"var"};
this.def["blinkTest_M_"] = {file: "blinkTest_c.html",line:26,type:"var"};
this.def["blinkTest_M"] = {file: "blinkTest_c.html",line:27,type:"var"};
this.def["blinkTest_step"] = {file: "blinkTest_c.html",line:30,type:"fcn"};
this.def["blinkTest_initialize"] = {file: "blinkTest_c.html",line:49,type:"fcn"};
this.def["blinkTest_terminate"] = {file: "blinkTest_c.html",line:71,type:"fcn"};
this.def["B_blinkTest_T"] = {file: "blinkTest_h.html",line:49,type:"type"};
this.def["DW_blinkTest_T"] = {file: "blinkTest_h.html",line:56,type:"type"};
this.def["RT_MODEL_blinkTest_T"] = {file: "blinkTest_types_h.html",line:20,type:"type"};
this.def["blinkTest_Blink_Init"] = {file: "Blink_c.html",line:28,type:"fcn"};
this.def["blinkTest_Blink"] = {file: "Blink_c.html",line:38,type:"fcn"};
this.def["int8_T"] = {file: "rtwtypes_h.html",line:47,type:"type"};
this.def["uint8_T"] = {file: "rtwtypes_h.html",line:48,type:"type"};
this.def["int16_T"] = {file: "rtwtypes_h.html",line:49,type:"type"};
this.def["uint16_T"] = {file: "rtwtypes_h.html",line:50,type:"type"};
this.def["int32_T"] = {file: "rtwtypes_h.html",line:51,type:"type"};
this.def["uint32_T"] = {file: "rtwtypes_h.html",line:52,type:"type"};
this.def["real32_T"] = {file: "rtwtypes_h.html",line:53,type:"type"};
this.def["real64_T"] = {file: "rtwtypes_h.html",line:54,type:"type"};
this.def["real_T"] = {file: "rtwtypes_h.html",line:60,type:"type"};
this.def["time_T"] = {file: "rtwtypes_h.html",line:61,type:"type"};
this.def["boolean_T"] = {file: "rtwtypes_h.html",line:62,type:"type"};
this.def["int_T"] = {file: "rtwtypes_h.html",line:63,type:"type"};
this.def["uint_T"] = {file: "rtwtypes_h.html",line:64,type:"type"};
this.def["ulong_T"] = {file: "rtwtypes_h.html",line:65,type:"type"};
this.def["char_T"] = {file: "rtwtypes_h.html",line:66,type:"type"};
this.def["uchar_T"] = {file: "rtwtypes_h.html",line:67,type:"type"};
this.def["byte_T"] = {file: "rtwtypes_h.html",line:68,type:"type"};
this.def["creal32_T"] = {file: "rtwtypes_h.html",line:78,type:"type"};
this.def["creal64_T"] = {file: "rtwtypes_h.html",line:83,type:"type"};
this.def["creal_T"] = {file: "rtwtypes_h.html",line:88,type:"type"};
this.def["cint8_T"] = {file: "rtwtypes_h.html",line:95,type:"type"};
this.def["cuint8_T"] = {file: "rtwtypes_h.html",line:102,type:"type"};
this.def["cint16_T"] = {file: "rtwtypes_h.html",line:109,type:"type"};
this.def["cuint16_T"] = {file: "rtwtypes_h.html",line:116,type:"type"};
this.def["cint32_T"] = {file: "rtwtypes_h.html",line:123,type:"type"};
this.def["cuint32_T"] = {file: "rtwtypes_h.html",line:130,type:"type"};
this.def["pointer_T"] = {file: "rtwtypes_h.html",line:148,type:"type"};
}
CodeDefine.instance = new CodeDefine();
var testHarnessInfo = {OwnerFileName: "", HarnessOwner: "", HarnessName: "", IsTestHarness: "0"};
var relPathToBuildDir = "../ert_main.c";
var fileSep = "\\";
var isPC = true;
function Html2SrcLink() {
	this.html2SrcPath = new Array;
	this.html2Root = new Array;
	this.html2SrcPath["ert_main_c.html"] = "../ert_main.c";
	this.html2Root["ert_main_c.html"] = "ert_main_c.html";
	this.html2SrcPath["blinkTest_c.html"] = "../blinkTest.c";
	this.html2Root["blinkTest_c.html"] = "blinkTest_c.html";
	this.html2SrcPath["blinkTest_h.html"] = "../blinkTest.h";
	this.html2Root["blinkTest_h.html"] = "blinkTest_h.html";
	this.html2SrcPath["blinkTest_private_h.html"] = "../blinkTest_private.h";
	this.html2Root["blinkTest_private_h.html"] = "blinkTest_private_h.html";
	this.html2SrcPath["blinkTest_types_h.html"] = "../blinkTest_types.h";
	this.html2Root["blinkTest_types_h.html"] = "blinkTest_types_h.html";
	this.html2SrcPath["Blink_c.html"] = "../Blink.c";
	this.html2Root["Blink_c.html"] = "Blink_c.html";
	this.html2SrcPath["Blink_h.html"] = "../Blink.h";
	this.html2Root["Blink_h.html"] = "Blink_h.html";
	this.html2SrcPath["rtwtypes_h.html"] = "../rtwtypes.h";
	this.html2Root["rtwtypes_h.html"] = "rtwtypes_h.html";
	this.getLink2Src = function (htmlFileName) {
		 if (this.html2SrcPath[htmlFileName])
			 return this.html2SrcPath[htmlFileName];
		 else
			 return null;
	}
	this.getLinkFromRoot = function (htmlFileName) {
		 if (this.html2Root[htmlFileName])
			 return this.html2Root[htmlFileName];
		 else
			 return null;
	}
}
Html2SrcLink.instance = new Html2SrcLink();
var fileList = [
"ert_main_c.html","blinkTest_c.html","blinkTest_h.html","blinkTest_private_h.html","blinkTest_types_h.html","Blink_c.html","Blink_h.html","rtwtypes_h.html"];
