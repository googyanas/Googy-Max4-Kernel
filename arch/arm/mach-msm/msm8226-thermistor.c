/*
 * fusion3-thermistor.c - thermistor of J-F Project
 *
 * Copyright (C) 2011 Samsung Electrnoics
 * SangYoung Son <hello.son@samsung.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

#include <mach/msm8x26-thermistor.h>
#include <mach/sec_thermistor.h>


#ifdef CONFIG_SEC_THERMISTOR
/*Below adc table is same as batt_temp_adc table*/
/* mismatch 8930 */
#if defined(CONFIG_MACH_BISCOTTO)
static struct sec_therm_adc_table temper_table_ap[] = {
	{220819,	 700},
	{226311,	 690},
	{234645,	 680},
	{242391,	 670},
	{250432,	 660},
	{256904,	 650},
	{267141,	 640},
	{277377,	 630},
	{284065,	 620},
	{291419,	 610},
	{299950,	 600},
	{312108,	 590},
	{324855,	 580},
	{333582,	 570},
	{340250,	 560},
	{354781,	 550},
	{367313,	 540},
	{381001,	 530},
	{397378,	 520},
	{412712,	 510},
	{424773,	 500},
	{437324,	 490},
	{449091,	 480},
	{460073,	 470},
	{476839,	 460},
	{495648,	 450},
	{512728,	 440},
	{529789,	 430},
	{547930,	 420},
	{566168,	 410},
	{585032,	 400},
	{603723,	 390},
	{623236,	 380},
	{639158,	 370},
	{658142,	 360},
	{680106,	 350},
	{699129,	 340},
	{721546,	 330},
	{738516,	 320},
	{761001,	 310},
	{780710,	 300},
	{803551,	 290},
	{825546,	 280},
	{845622,	 270},
	{867587,	 260},
	{888629,	 250},
	{909201,	 240},
	{932989,	 230},
	{955345,	 220},
	{978094,	 210},
	{996921,	 200},
	{1021925,	 190},
	{1043280,	 180},
	{1069696,	 170},
	{1097192,	 160},
	{1121543,	 150},
	{1145805,	 140},
	{1170691,	 130},
	{1190343,	 120},
	{1209503,	 110},
	{1226462,	 100},
	{1244410,	  90},
	{1261550,	  80},
	{1280004,	  70},
	{1300007,	  60},
	{1312754,	  50},
	{1327168,	  40},
	{1344818,	  30},
	{1363743,	  20},
	{1381589,	  10},
	{1394728,	   0},
	{1411299,	 -10},
	{1430028,	 -20},
	{1448562,	 -30},
	{1463268,	 -40},
	{1480232,	 -50},
	{1498176,  -60},
	{1512414,	 -70},
	{1527290,	 -80},
	{1540064,	 -90},
	{1551413,	 -100},
	{1562696,	 -110},
	{1573893,	 -120},
	{1585346,	 -130},
	{1593779,	 -140},
	{1601623,	 -150},
	{1608623,	 -160},
	{1616123,	 -170},
	{1623123,	 -180},
	{1630123,	 -190},
	{1637123,	 -200},
};
#elif defined(CONFIG_MACH_LT02)
static struct sec_therm_adc_table temper_table_ap[] = {
	{233578,	700},
	{270598,	650},
	{316066,	600},
	{377415,	550},
	{445072,	500},
	{515451,	450},
	{597022,	400},
	{687765,	350},
	{785859,	300},
	{876244,	250},
	{984861,	200},
	{1100886,	150},
	{1205141,	100},
	{1307015,	50},
	{1397464,	0},
	{1481110,	-50},
	{1547236,	-100},
	{1606714,	-150},
	{1652742,	-200},
	{1687794,	-250},
	{1718578,	-300},
};
#elif defined(CONFIG_MACH_MELIUS) || defined(CONFIG_MACH_CRATER) || defined(CONFIG_MACH_BAFFIN)
static struct sec_therm_adc_table temper_table_ap[] = {
	{220819,	 700},
	{226311,	 690},
	{234645,	 680},
	{242391,	 670},
	{250432,	 660},
	{256904,	 650},
	{267141,	 640},
	{277377,	 630},
	{284065,	 620},
	{291419,	 610},
	{299950,	 600},
	{312108,	 590},
	{324855,	 580},
	{333582,	 570},
	{340250,	 560},
	{354781,	 550},
	{367313,	 540},
	{381001,	 530},
	{397378,	 520},
	{412712,	 510},
	{424773,	 500},
	{437324,	 490},
	{449091,	 480},
	{460073,	 470},
	{476839,	 460},
	{495648,	 450},
	{512728,	 440},
	{529789,	 430},
	{547930,	 420},
	{566168,	 410},
	{585032,	 400},
	{603723,	 390},
	{623236,	 380},
	{639158,	 370},
	{658142,	 360},
	{680106,	 350},
	{699129,	 340},
	{721546,	 330},
	{738516,	 320},
	{761001,	 310},
	{780710,	 300},
	{803551,	 290},
	{825546,	 280},
	{845622,	 270},
	{867587,	 260},
	{888629,	 250},
	{909201,	 240},
	{932989,	 230},
	{955345,	 220},
	{978094,	 210},
	{996921,	 200},
	{1021925,	 190},
	{1043280,	 180},
	{1069696,	 170},
	{1097192,	 160},
	{1121543,	 150},
	{1145805,	 140},
	{1170691,	 130},
	{1190343,	 120},
	{1209503,	 110},
	{1226462,	 100},
	{1244410,	  90},
	{1261550,	  80},
	{1280004,	  70},
	{1300007,	  60},
	{1312754,	  50},
	{1327168,	  40},
	{1344818,	  30},
	{1363743,	  20},
	{1381589,	  10},
	{1394728,	   0},
	{1411299,	 -10},
	{1430028,	 -20},
	{1448562,	 -30},
	{1463268,	 -40},
	{1480232,	 -50},
	{1498176,  -60},
	{1512414,	 -70},
	{1527290,	 -80},
	{1540064,	 -90},
	{1551413,	 -100},
	{1562696,	 -110},
	{1573893,	 -120},
	{1585346,	 -130},
	{1593779,	 -140},
	{1601623,	 -150},
	{1608623,	 -160},
	{1616123,	 -170},
	{1623123,	 -180},
	{1630123,	 -190},
	{1637123,	 -200},
};
#elif defined (CONFIG_MACH_SERRANO)
static struct sec_therm_adc_table temper_table_ap[] = {
	{237490,	 700},
	{238228,	 650},
	{238376,	 640},
	{238524,	 630},
	{238672,	 620},
	{238820,	 610},
	{238966,	 600},
	{263653,	 590},
	{288340,	 580},
	{313027,	 570},
	{337714,	 560},
	{362400,	 550},
	{374228,	 540},
	{386056,	 530},
	{397884,	 520},
	{409712,	 510},
	{421544,	 500},
	{435844,	 490},
	{450144,	 480},
	{464444,	 470},
	{478744,	 460},
	{493052,	 450},
	{507064,	 440},
	{521076,	 430},
	{535088,	 420},
	{549100,	 410},
	{563112,	 400},
	{580456,	 390},
	{597800,	 380},
	{615144,	 370},
	{632488,	 360},
	{649832,	 350},
	{671713,	 340},
	{693594,	 330},
	{715475,	 320},
	{737356,	 310},
	{759237,	 300},
	{958365,	 200},
	{1210206,	 100},
	{1399000,	   0},
	{1535550,	 -100},
	{1626500,	 -200},
	{1697050,	 -300},
};
#elif defined(CONFIG_SEC_BERLUTI_PROJECT)
static struct sec_therm_adc_table temper_table_ap[] = {
	{25204, 900},
	{25624, 850},
	{26045, 800},
	{26350, 750},
	{26656, 700},
	{27101, 650},
	{27554, 600},
	{27650, 590},
	{27746, 580},
	{27842, 570},
	{27938, 560},
	{28034, 550},
	{28152, 540},
	{28270, 530},
	{28388, 520},
	{28506, 510},
	{28625, 500},
	{28766, 490},
	{28907, 480},
	{29048, 470},
	{29189, 460},
	{29330, 450},
	{29485, 440},
	{29640, 430},
	{29795, 420},
	{29950, 410},
	{30107, 400},
	{30298, 390},
	{30489, 380},
	{30680, 370},
	{30871, 360},
	{31064, 350},
	{31239, 340},
	{31414, 330},
	{31589, 320},
	{31764, 310},
	{31940, 300},
	{34068, 200},
	{36339, 100},
	{38445, 0},
	{39784, -100},
	{41874, -200},
};
#elif defined (CONFIG_MACH_VICTORLTE_CTC)
static struct sec_therm_adc_table temper_table_ap[] = {
	{26026, 900},
	{26086, 850},
	{26146, 800},
	{26393, 750},
	{26785, 700},
	{26865, 690},
	{26945, 680},
	{27026, 670},
	{27106, 660},
	{27187, 650},
	{27281, 640},
	{27375, 630},
	{27470, 620},
	{27564, 610},
	{27659, 600},
	{27766, 590},
	{27873, 580},
	{27980, 570},
	{28087, 560},
	{28194, 550},
	{28314, 540},
	{28434, 530},
	{28554, 520},
	{28674, 510},
	{28794, 500},
	{28934, 490},
	{29074, 480},
	{29214, 470},
	{29354, 460},
	{29494, 450},
	{29653, 440},
	{29812, 430},
	{29972, 420},
	{30131, 410},
	{30291, 400},
	{30473, 390},
	{30655, 380},
	{30838, 370},
	{31020, 360},
	{31203, 350},
	{31371, 340},
	{31539, 330},
	{31708, 320},
	{31876, 310},
	{32045, 300},
};
#elif defined (CONFIG_ARCH_MSM8226)
static struct sec_therm_adc_table temper_table_ap[] = {
	{23196, 900},
	{23803, 850},
	{24437, 800},
	{25111, 750},
	{25889, 700},
	{26669, 650},
	{27299, 620},
	{27378, 610},
	{27514, 600},
	{27614, 590},
	{27803, 580},
	{27923, 570},
	{28268, 560},
	{28387, 550},
	{28509, 540},
	{28637, 530},
	{28758, 520},
	{28889, 510},
	{29025, 500},
	{29115, 490},
	{29286, 480},
	{29446, 470},
	{29620, 460},
	{29759, 450},
	{29945, 440},
	{30107, 430},
	{30266, 420},
	{30449, 410},
	{30612, 400},
	{30800, 390},
	{30980, 380},
	{31153, 370},
	{31352, 360},
	{31519, 350},
	{31704, 340},
	{31909, 330},
	{32023, 320},
	{32290, 310},
	{32379, 300},
};
#elif defined (CONFIG_MACH_CANE)
static struct sec_therm_adc_table temper_table_ap[] = {
	{237490,	 700},
	{238228,	 650},
	{238376,	 640},
	{238524,	 630},
	{238672,	 620},
	{238820,	 610},
	{238966,	 600},
	{263653,	 590},
	{288340,	 580},
	{313027,	 570},
	{337714,	 560},
	{362400,	 550},
	{374228,	 540},
	{386056,	 530},
	{397884,	 520},
	{409712,	 510},
	{421544,	 500},
	{435844,	 490},
	{450144,	 480},
	{464444,	 470},
	{478744,	 460},
	{493052,	 450},
	{507064,	 440},
	{521076,	 430},
	{535088,	 420},
	{549100,	 410},
	{563112,	 400},
	{580456,	 390},
	{597800,	 380},
	{615144,	 370},
	{632488,	 360},
	{649832,	 350},
	{671713,	 340},
	{693594,	 330},
	{715475,	 320},
	{737356,	 310},
	{759237,	 300},
	{958365,	 200},
	{1210206,	 100},
	{1399000,	   0},
	{1535550,	 -100},
	{1626500,	 -200},
	{1697050,	 -300},
};
/*
#elif defined(CONFIG_MACH_CRATER) || defined(CONFIG_MACH_BAFFIN)
static struct sec_therm_adc_table temper_table_ap[] = {
	{240910,    700},
	{278128,    650},
	{322194,    600},
	{379784,    550},
	{439390,    500},
	{520574,    450},
	{599342,    400},
	{679372,    350},
	{772749,    300},
	{881036,    250},
	{982737,    200},
	{1091602,   150},
	{1196111,   100},
	{1291930,   50},
	{1402210,   0},
	{1466921,   -50},
	{1551839,   -100},
	{1609876,   -150},
	{1652458,   -200},
};
*/
#elif defined (CONFIG_MACH_KS02)
static struct sec_therm_adc_table temper_table_ap[] = {
	{207438,  700},
	{215494,  690},
	{223549,  680},
	{231604,  670},
	{239659,  660},
	{247714,  650},
	{255769,  640},
	{263824,  630},
	{271879,  620},
	{281552,  610},
	{291225,  600},
	{301979,  590},
	{312732,  580},
	{323486,  570},
	{334239,  560},
	{344993,  550},
	{355746,  540},
	{366500,  530},
	{377253,  520},
	{389704,  510},
	{402154,  500},
	{416147,  490},
	{430139,  480},
	{443766,  470},
	{457392,  460},
	{472718,  450},
	{488044,  440},
	{503192,  430},
	{518340,  420},
	{535218,  410},
	{552095,  400},
	{570072,  390},
	{588050,  380},
	{606027,  370},
	{624005,  360},
	{641982,  350},
	{659960,  340},
	{677937,  330},
	{695914,  320},
	{713892,  310},
	{731869,  300},
	{749847,  290},
	{767824,  280},
	{785802,  270},
	{803779,  260},
	{821757,  250},
	{839734,  240},
	{857711,  230},
	{875689,  220},
	{893666,  210},
	{911644,  200},
	{929621,  190},
	{947599,  180},
	{965576,  170},
	{983553,  160},
	{1001531,  150},
	{1019508,  140},
	{1037486,  130},
	{1055463,  120},
	{1073441,  110},
	{1091418,  100},
	{1109395,   90},
	{1127373,   80},
	{1145350,   70},
	{1163328,   60},
	{1181305,   50},
	{1199283,   40},
	{1217260,   30},
	{1235237,   20},
	{1253215,   10},
	{1271192,    0},
	{1289170,  -10},
	{1307147,  -20},
	{1325125,  -30},
	{1343102,  -40},
	{1361080,  -50},
	{1379057,  -60},
	{1397034,  -70},
	{1415012,  -80},
	{1432989,  -90},
	{1450967,  -100},
	{1468944,  -110},
	{1486922,  -120},
	{1504899,  -130},
	{1522876,  -140},
	{1540854,  -150},
	{1558831,  -160},
	{1576809,  -170},
	{1594786,  -180},
	{1612764,  -190},
	{1630741,  -200},
};
#else
static struct sec_therm_adc_table temper_table_ap[] = {
	{27188,	 700},
	{27271,	 690},
	{27355,	 680},
	{27438,	 670},
	{27522,	 660},
	{27605,	 650},
	{27721,	 640},
	{27836,	 630},
	{27952,	 620},
	{28067,	 610},
	{28182,	 600},
	{28296,	 590},
	{28409,	 580},
	{28522,	 570},
	{28635,	 560},
	{28748,	 550},
	{28852,	 540},
	{28955,	 530},
	{29058,	 520},
	{29161,	 510},
	{28182,	 500},
	{29410,	 490},
	{29555,	 480},
	{29700,	 470},
	{29845,	 460},
	{29990,	 450},
	{30188,	 440},
	{30386,	 430},
	{30584,	 420},
	{30782,	 410},
	{30981,	 400},
	{31164,	 390},
	{31347,	 380},
	{31530,	 370},
	{31713,	 360},
	{31896,	 350},
	{32081,	 340},
	{32266,	 330},
	{32450,	 320},
	{32635,	 310},
	{32820,	 300},
	{33047,	 290},
	{33274,	 280},
	{33502,	 270},
	{33729,	 260},
	{33956,	 250},
	{34172,	 240},
	{34388,	 230},
	{34605,	 220},
	{34821,	 210},
	{35037,	 200},
	{35246,	 190},
	{35455,	 180},
	{35664,	 170},
	{35873,	 160},
	{36083,	 150},
	{36302,	 140},
	{36522,	 130},
	{36741,	 120},
	{36961,	 110},
	{37180,	 100},
	{37398,	  90},
	{37615,	  80},
	{37833,	  70},
	{38050,	  60},
	{38267,	  50},
	{38443,	  40},
	{38620,	  30},
	{38796,	  20},
	{38972,	  10},
	{39148,	   0},
	{39302,	 -10},
	{39455,	 -20},
	{39609,	 -30},
	{39762,	 -40},
	{39916,	 -50},
	{40050,  -60},
	{40184,	 -70},
	{40318,	 -80},
	{40452,	 -90},
	{40586,	 -100},
	{40713,	 -110},
	{40841,	 -120},
	{40968,	 -130},
	{41095,	 -140},
	{41222,	 -150},
	{41292,	 -160},
	{41363,	 -170},
	{41433,	 -180},
	{41503,	 -190},
	{41573,	 -200},
};
#endif
/* when the next level is same as prev, returns -1 */
//static int get_fusion3_siop_level(int temp)
static int get_msm8x26_siop_level(int temp)
{
	static int prev_temp = 400;
	static int prev_level;
	int level = -1;

#if defined(CONFIG_MACH_JF_DCM)
	return -1;
#endif

	if (temp > prev_temp) {
		if (temp >= 540)
			level = 4;
		else if (temp >= 530)
			level = 3;
		else if (temp >= 480)
			level = 2;
		else if (temp >= 440)
			level = 1;
		else
			level = 0;
	} else {
		if (temp < 410)
			level = 0;
		else if (temp < 440)
			level = 1;
		else if (temp < 480)
			level = 2;
		else if (temp < 530)
			level = 3;
		else
			level = 4;

		if (level > prev_level)
			level = prev_level;
	}

	prev_temp = temp;
//	if (prev_level == level)
//		return -1;

	prev_level = level;

	return level;
}


struct sec_therm_platform_data sec_therm_pdata = {
	.adc_arr_size	= ARRAY_SIZE(temper_table_ap),
	.adc_table	= temper_table_ap,
	.polling_interval = 30 * 1000, /* msecs */
	.get_siop_level = get_msm8x26_siop_level,
	.no_polling     = 1,
};

struct platform_device sec_device_thermistor = {
	.name = "sec-thermistor",
	.id = -1,
	.dev.platform_data = &sec_therm_pdata,
};

struct sec_therm_platform_data * fill_therm_pdata(struct platform_device *pdev)
{
	pdev->dev.platform_data = &sec_therm_pdata;
	pdev->id = -1;
	return &sec_therm_pdata;
}

#endif
