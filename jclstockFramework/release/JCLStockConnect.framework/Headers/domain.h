#pragma once

namespace XWealth
{
    enum DomainIndex
    {
        DI_NONE = -1,
        DI_SHAG = 0,				// 上海A股
        DI_SHBG = 1,				// 上海B股
        DI_SZAG = 2,				// 深圳A股
        DI_SZBG = 3,				// 深圳B股
        DI_SHBOUD = 4,				// 上海债券
        DI_SZBOUD = 5,				// 深圳债券
        DI_AG = 6,					// A股
        DI_BG = 7,					// B股
        DI_BOND = 8,				// 债券
        DI_FUND = 9,				// 基金
        DI_ALLGP = 10,				// 所有品种
        DI_ALLINDEX = 11,				// 所有指数
        DI_ZHONGXIAO = 12,			// 中小企业
        DI_GEM = 13,				// 创业板
        DI_SB = 14,					// 股转系统
        DI_DELISTING = 15,			// 退市整理版

        DI_OPTION = 17,				// 权证
        //DI_GEM = 18,				// 创业板
        DI_BH = 19,					// 渤海商品
        DI_QH_DLSP = 20,			// 大连商品
        DI_QH_ZZSP = 21,			// 郑州商品
        DI_QH_SHSP = 22,			// 上海期货
        DI_QH_GZQH = 23,			// 股指期货
        DI_SJ = 24,					// 上海金
        DI_LDJ = 25,				// 伦敦金
        DI_TJ = 26,					// 天津贵金属
        DI_BTB,						// 比特币
        DI_KZZ,						// 可转债
        DI_SCIENCE_TECHNOLOGY,		// 科创板

        DI_ALL_BLOCK = 30,			// 所有板块
        DI_AREA = 31,				// 地域
        DI_INDUSTRY = 32,			// 行业
        DI_CONCEPT = 33,			// 概念

        DI_RM_BLOCK_ALL,			//热门板块-所有
        DI_RM_BLOCK_AREA,			//热门板块-地域
        DI_RM_BLOCK_INDUSTRY,		//热门板块-行业
        DI_RM_BLOCK_CONCEPT,		//热门板块-概念

        DI_HX,						//海峡艺术品交易所-所有品种
        DI_HX_YSZB,					//海峡艺术品交易所-艺术主板
        DI_HX_YSXB,					//海峡艺术品交易所-艺术新版
        DI_HX_YBSC,					//海峡艺术品交易所-邮票收藏
        DI_HX_QBSC,					//海峡艺术品交易所-钱币收藏
        DI_HX_PSJK,					//海峡艺术品交易所-配售缴款
        DI_HX_CCQB,					//海峡艺术品交易所-茶产权版

        DI_QH_QL = 50,				//齐鲁商品
        DI_QH_HQXG,					//横琴稀贵
        DI_QH_ALL_LDJ,				//伦敦金
        DI_FUND_PENGHUA,			//鹏华基金公司发行的17个基金品种
        DI_TEA,						//广州茶叶商品期货-所有品种
        DI_TEA_ZS,					//广州茶叶商品期货-指数
        DI_TEA_GOODS,				//广州茶叶商品期货-商品
        DI_DPT,                     //甬交所
        DI_HK,						//港股

        DI_AG_HQBJ = 70,				//沪深A股-行情报价
        DI_AG_ZJJC,					//沪深A股-资金决策
        DI_AG_CWSJ,					//沪深A股-财务数据
        DI_AG_HQTJ,					//沪深A股-行情统计

        DI_OIL = 80,                 //原油
        DI_BKZJ = 80,				//板块资金
        DI_RMQL = 81,				//热门强龙
        DI_DTXG = 82,				//动态选股

        DI_DDTJ = 90,				//大单统计 同沪深A股资金决策
        DI_JZTZ = 91,				//价值投资

        //板块个股 modify by cjf
        DI_BLOCK_INDEX_MIN = 100,		//新的板块个数很多，在后面重新定义序号
        DI_FIRST_AREA_BLOCK = 100,
        DI_LAST_AREA_BLOCK = 199,
        DI_FIRST_INDUSTRY_BLOCK = 200,
        DI_LAST_INDUSTRY_BLOCK = 299,
        DI_FIRST_CONCEPT_BLOCK = 300,
        DI_LAST_CONCEPT_BLOCK = 1300,
        DI_BLOCK_INDEX_MAX = 1300,

        DI_FULLSCREEN_BHGOODS = 1501,			// 渤海商品
        DI_FULLSCREEN_FIVE,				// 5分钟领涨股(A股涨速排名)
        DI_FULLSCREEN_CURRDAY,			// 当日领涨股(A股涨幅排名)
        DI_FULLSCREEN_CURRDAYBK,		// 当日领涨板块(板块指数涨幅排名)
        DI_FULLSCREEN_SHAG,
        DI_FULLSCREEN_SZAG,
        DI_FULLSCREEN_AREA,				// 地域
        DI_FULLSCREEN_INDUSTRY,			// 行业
        DI_FULLSCREEN_CONCEPT,			// 概念
        DI_FULLSCREEN_ZXG,				//自选股
        DI_FULLSCREEN_CURRDAYBK_GG = 1000,	//全景图板块成份股设置表头专用，不做分类使用
        DI_FULLSCREEN_CURRDAYBK_GG_FIRST = DI_FULLSCREEN_CURRDAYBK_GG + DI_BLOCK_INDEX_MIN,
        DI_FULLSCREEN_CURRDAYBK_GG_LAST = DI_FULLSCREEN_CURRDAYBK_GG + DI_BLOCK_INDEX_MAX,

        DI_FUND_HOMEPAGE = 4000,		// 分级基金-B基金
        DI_FUND_SUBJECT,				// 主题基金（挂钩指数、母基金、A基金、B基金）
        DI_FUND_B,						// B类基金
        DI_FUND_SUBJECT_HOT,			// 主题基金
        DI_FUND_HOMEPAGE_A,				// 分级基金-A基金
        DI_FUND_HOMEPAGE_M,				// 分级基金-母基
        DI_FUND_HOMEPAGE_FJ_T2,			// 分级基金-分级T+2
        DI_FUND_HOMEPAGE_FJ_T1,			// 分级基金-分级T+1
        DI_FUND_HOMEPAGE_FJ_T0,			// 分级基金-分级T+0
        DI_FUND_MONEY_T0,				// 货币基金T+0
        DI_FUND_MONEY_T1,				// 货币基金T+1

        //add by yl
        DI_FUND_TYPE_ALL,               //分级基金-所有分类
        DI_FUND_TYPE_STOCK,             //分级基金-股票型
        DI_FUND_TYPE_INDEX,             //分级基金-指数型
        DI_FUND_TYPE_BOUD,              //分级基金-债券型

        DI_FUND_B_HOLD,					// B类基金-重仓股
        //新增B级基金主题分类domain       袁亮      20150910
        DI_FUND_B_SUBJECT,
        DI_FUND_PROFIT,					//折价轮动套利报价表

        DI_SORT_MAX = 9000,				// 服务器支持排序分界值（以后可以调整）
        DI_SYSTEMBLOCK,					// 系统板块

        DI_CUSTOM,						// 自选股
        DI_CUSTOM_ZJJC,					//自选股-资金决策
        DI_CUSTOM_CWSH,					//自选股-财务数据
        DI_CUSTOM_HQTJ,					//自选股-行情统计

        DI_SHHG = 9007,						// 上证回购
        DI_SZHG,						// 深圳回购

        DI_ZBXG = 9011,		        	// 指标选股  9011  wangzhuo 	

        DI_FUND_A,						// A类轮动

        DI_IK_UP = 9100,				//智能K线 最可能上涨
        DI_IK_ZY,						//智能K线 匹配涨最优
        DI_IK_XS,						//智能K线 今日最相似
        DI_GZ_HY,						//个股诊断 行业
        DI_GZ_ZS,						//个股诊断 指数
        DI_GZ_CUSTOM,					//个股诊断 自选股

        DI_CUSTOM_HQCAL = 9018,			//行情计算
        DI_CXQN_SCDK = 9200,			//次新擒牛 首次打开
        DI_CXQN_CGHF = 9201,			//次新擒牛 成功回封
        DI_CXQN_YZLB = 9202,			//次新擒牛 一字连板
        DI_CXQN_ZCXG = 9203,			//次新擒牛 再创新高
        DI_CXQN_JDCD = 9204,			//次新擒牛 阶段超跌
        DI_CXQN_DJQL = 9205,			//次新擒牛 低价潜力

        DI_JHJJ_ZTSP = 9300,			//集合竞价 涨停试盘
        DI_JHJJ_DTSP = 9301,			//集合竞价 跌停试盘
        DI_JHJJ_JJKD = 9302,			//集合竞价 集竞看多
        DI_JHJJ_JJKK = 9303,			//集合竞价 集竞看空
        DI_JHJJ_DKHZ = 9304,			//集合竞价 多空混战

        DI_ZTZY = 9400,			//涨停捉妖		

        DI_CLZX_JRTC = 9410,			//策略中心 今日调仓
        DI_CLZX_DQCC = 9411,			//策略中心 当前持仓
        DI_CLZX_CLNG = 9412,			//策略中心 策略牛股

        DI_SCRD = 9450,			//市场热点

        DI_AG_ZSOTHER = 9500,		   //其它指数
        DI_FILTER = 9588,				// 过滤器
        DI_GPCXG = 9600,				// 股票池
        DI_AG_GLPZ = 9700,				// 关联品种

        DI_FIRST_FORMULAR_BLOCK = 9800,	//云选股板块
        DI_LAST_FORMULAR_BLOCK = 9900,

        DI_CONDITION = 9999,			// 条件股		注: 此处DI_CONDITION一定要设置为DI_FIRST_CUSTOM_BLOCK-1
        DI_FIRST_CUSTOM_BLOCK = 10000,	// 自定义板块
    };
}
