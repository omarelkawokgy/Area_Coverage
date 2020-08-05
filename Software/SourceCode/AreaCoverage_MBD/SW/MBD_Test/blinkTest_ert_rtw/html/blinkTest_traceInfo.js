function RTW_Sid2UrlHash() {
	this.urlHashMap = new Array();
	/* <Root>/Blink */
	this.urlHashMap["blinkTest:3"] = "blinkTest.c:32,35,64,67&Blink.c:27,37";
	/* <Root>/Chart */
	this.urlHashMap["blinkTest:5"] = "blinkTest.c:37";
	/* <Root>/Pin */
	this.urlHashMap["blinkTest:6"] = "blinkTest.c:38";
	/* <Root>/Scope */
	this.urlHashMap["blinkTest:7"] = "msg=rtwMsg_SimulationReducedBlock&block=blinkTest:7";
	/* <S1>/Chart */
	this.urlHashMap["blinkTest:1"] = "blinkTest.h:48,53,54,55&Blink.c:22,30,40,80";
	/* <S2>:2 */
	this.urlHashMap["blinkTest:5:2"] = "blinkTest.c:43";
	/* <S2>:4 */
	this.urlHashMap["blinkTest:5:4"] = "blinkTest.c:44";
	/* <S3>:2 */
	this.urlHashMap["blinkTest:1:2"] = "Blink.c:56,59,75";
	/* <S3>:1 */
	this.urlHashMap["blinkTest:1:1"] = "Blink.c:65,69";
	/* <S3>:6 */
	this.urlHashMap["blinkTest:1:6"] = "Blink.c:52";
	/* <S3>:3 */
	this.urlHashMap["blinkTest:1:3"] = "Blink.c:71";
	/* <S3>:4 */
	this.urlHashMap["blinkTest:1:4"] = "Blink.c:61";
	this.getUrlHash = function(sid) { return this.urlHashMap[sid];}
}
RTW_Sid2UrlHash.instance = new RTW_Sid2UrlHash();
function RTW_rtwnameSIDMap() {
	this.rtwnameHashMap = new Array();
	this.sidHashMap = new Array();
	this.rtwnameHashMap["<Root>"] = {sid: "blinkTest"};
	this.sidHashMap["blinkTest"] = {rtwname: "<Root>"};
	this.rtwnameHashMap["<S1>"] = {sid: "blinkTest:3"};
	this.sidHashMap["blinkTest:3"] = {rtwname: "<S1>"};
	this.rtwnameHashMap["<S2>"] = {sid: "blinkTest:5"};
	this.sidHashMap["blinkTest:5"] = {rtwname: "<S2>"};
	this.rtwnameHashMap["<S3>"] = {sid: "blinkTest:1"};
	this.sidHashMap["blinkTest:1"] = {rtwname: "<S3>"};
	this.rtwnameHashMap["<Root>/Blink"] = {sid: "blinkTest:3"};
	this.sidHashMap["blinkTest:3"] = {rtwname: "<Root>/Blink"};
	this.rtwnameHashMap["<Root>/Chart"] = {sid: "blinkTest:5"};
	this.sidHashMap["blinkTest:5"] = {rtwname: "<Root>/Chart"};
	this.rtwnameHashMap["<Root>/Pin"] = {sid: "blinkTest:6"};
	this.sidHashMap["blinkTest:6"] = {rtwname: "<Root>/Pin"};
	this.rtwnameHashMap["<Root>/Scope"] = {sid: "blinkTest:7"};
	this.sidHashMap["blinkTest:7"] = {rtwname: "<Root>/Scope"};
	this.rtwnameHashMap["<S1>/Chart"] = {sid: "blinkTest:1"};
	this.sidHashMap["blinkTest:1"] = {rtwname: "<S1>/Chart"};
	this.rtwnameHashMap["<S1>/Out1"] = {sid: "blinkTest:4"};
	this.sidHashMap["blinkTest:4"] = {rtwname: "<S1>/Out1"};
	this.rtwnameHashMap["<S2>:2"] = {sid: "blinkTest:5:2"};
	this.sidHashMap["blinkTest:5:2"] = {rtwname: "<S2>:2"};
	this.rtwnameHashMap["<S2>:4"] = {sid: "blinkTest:5:4"};
	this.sidHashMap["blinkTest:5:4"] = {rtwname: "<S2>:4"};
	this.rtwnameHashMap["<S3>:2"] = {sid: "blinkTest:1:2"};
	this.sidHashMap["blinkTest:1:2"] = {rtwname: "<S3>:2"};
	this.rtwnameHashMap["<S3>:1"] = {sid: "blinkTest:1:1"};
	this.sidHashMap["blinkTest:1:1"] = {rtwname: "<S3>:1"};
	this.rtwnameHashMap["<S3>:6"] = {sid: "blinkTest:1:6"};
	this.sidHashMap["blinkTest:1:6"] = {rtwname: "<S3>:6"};
	this.rtwnameHashMap["<S3>:3"] = {sid: "blinkTest:1:3"};
	this.sidHashMap["blinkTest:1:3"] = {rtwname: "<S3>:3"};
	this.rtwnameHashMap["<S3>:4"] = {sid: "blinkTest:1:4"};
	this.sidHashMap["blinkTest:1:4"] = {rtwname: "<S3>:4"};
	this.getSID = function(rtwname) { return this.rtwnameHashMap[rtwname];}
	this.getRtwname = function(sid) { return this.sidHashMap[sid];}
}
RTW_rtwnameSIDMap.instance = new RTW_rtwnameSIDMap();
