#pragma once

#import <string>
#import <Foundation/Foundation.h>
#import "Jclprotocol.pbobjc.h"
constexpr uint8_t NOW_VERSION = 12;
constexpr int MMP_COUNT = 10;
constexpr int BS_QUEUE_COUNT = 50;

constexpr short EXCHANGE_TYPE_NONE = -1;
constexpr short EXCHANGE_TYPE_SZSE = 0;    //深圳证券交易所
constexpr short EXCHANGE_TYPE_SHSE = 1;    //上海证券交易所
constexpr short EXCHANGE_TYPE_HKEX = 2;    //香港证券交易所
constexpr short EXCHANGE_TYPE_CFFEX = 3;    //中国金融期货交易所
constexpr short EXCHANGE_TYPE_SHFE = 4;    //上海期货交易所
constexpr short EXCHANGE_TYPE_DCE = 5;    //大连商品交易所
constexpr short EXCHANGE_TYPE_ZC = 6;    //郑州商品交易所
constexpr short EXCHANGE_TYPE_BH = 7;    //天津渤海商品交易所
constexpr short EXCHANGE_TYPE_SHGE = 8;    //上海黄金交易所
constexpr short EXCHANGE_TYPE_LDJ = 9;    //伦敦黄金交易市场
constexpr short EXCHANGE_TYPE_TPME = 10;    //天津贵金属交易所
constexpr short EXCHANGE_TYPE_WH = 11;    //国际外汇交易所
constexpr short EXCHANGE_TYPE_HX = 12;    //福建海峡文化产权交易所
constexpr short EXCHANGE_TYPE_HQXG = 13;    //横琴稀贵
constexpr short EXCHANGE_TYPE_QL = 14;    //齐鲁行情
constexpr short EXCHANGE_TYPE_FOREIGN_FUTURES = 15;    //国际期货交易市场
constexpr short EXCHANGE_TYPE_EUREX = 16;    //香港期货交易所
constexpr short EXCHANGE_TYPE_LDJ2 = 17;    //伦敦金2
constexpr short EXCHANGE_TYPE_BG = 18;    //宝钢
constexpr short EXCHANGE_TYPE_TEA = 19;    //茶叶商品交易所
constexpr short EXCHANGE_TYPE_COMMON = 20;    //行情通用市场
constexpr short EXCHANGE_TYPE_OIL = 24;    //上海国际能源交易中心
constexpr short MAX_MARKETNUM = 25;

constexpr int CODE_LEN = 32;
constexpr int NAME_LEN = 32;

constexpr int INOUT_FLAG_BUY = 0;    //主动性买盘
constexpr int INOUT_FLAG_SELL = 1;    //主动性卖盘
constexpr int INOUT_FLAG_UNKNOWN = 2;    //不明盘
constexpr int INOUT_FLAG_KCB = 3;    //盘口科创板
constexpr int INOUT_FLAG_JHJJ = 4;    //集合竞价

constexpr int QUOTE_SOURCE_TYPE_NONE = 0;    //未知来源
constexpr int QUOTE_SOURCE_TYPE_L1 = 1;    //Level1行情源
constexpr int QUOTE_SOURCE_TYPE_L2 = 2;    //Level2行情源

constexpr int STOCK_STATUS_NONE = 0;    //未知交易状态
constexpr int STOCK_STATUS_ADD = 1;    //新品种上市
constexpr int STOCK_STATUS_BETW = 2;    //交易时间段禁止所有交易活动
constexpr int STOCK_STATUS_BREADK = 3;    //休市,无撮合和市场信息披露
constexpr int STOCK_STATUS_CLOSE = 4;    //闭市,计算闭市价格
constexpr int STOCK_STATUS_DEL = 5;    //品种待删除
constexpr int STOCK_STATUS_ENDTR = 6;    //交易结束
constexpr int STOCK_STATUS_FCALL = 7;    //固定价格集合竞价
constexpr int STOCK_STATUS_HALT = 8;    //暂停(禁止所有交易活动)
constexpr int STOCK_STATUS_SUSP = 9;    //暂停(允许撤单)
constexpr int STOCK_STATUS_ICALL = 10;    //盘中集合竞价
constexpr int STOCK_STATUS_IOBB = 11;    //盘中集合竞价OBB(订单薄平衡)
constexpr int STOCK_STATUS_IPOBB = 12;    //盘中集合竞价PreOBB
constexpr int STOCK_STATUS_OCALL = 13;    //开市集合竞价
constexpr int STOCK_STATUS_OOBB = 14;    //开市集合竞价OBB
constexpr int STOCK_STATUS_OPOBB = 15;    //开市集合竞价PreOBB
constexpr int STOCK_STATUS_NOTRD = 16;    //非交易,支持非交易服务
constexpr int STOCK_STATUS_POSTR = 17;    //盘后处理
constexpr int STOCK_STATUS_PRETR = 18;    //盘前处理
constexpr int STOCK_STATUS_START = 19;    //启动
constexpr int STOCK_STATUS_TRADE = 20;    //连续自动撮合
constexpr int STOCK_STATUS_VOLA = 21;    //波动性中断(连续交易&集合竞价交易)
constexpr int STOCK_STATUS_CCALL = 22;    //尾盘集合竞价
constexpr int STOCK_STATUS_PCALL = 23;    // 科创板15:00 - 15:05
constexpr int STOCK_STATUS_POSMT = 24;    // 科创板15:05 - 15:30
constexpr int STOCK_STATUS_ENDPT = 25;    // 科创板15:30 之后
constexpr int STOCK_STATUS_POSSP = 26;    // 科创板停牌

constexpr int64_t JCLTIME_MOD_SECOND    = 1000ll;
constexpr int64_t JCLTIME_MOD_MINUTE    = 100ll * JCLTIME_MOD_SECOND;
constexpr int64_t JCLTIME_MOD_HOUR      = 100ll * JCLTIME_MOD_MINUTE;
constexpr int64_t JCLTIME_MOD_DATE      = 100ll * JCLTIME_MOD_HOUR;
constexpr int64_t JCLTIME_MOD_MONTH     = 100ll * JCLTIME_MOD_DATE;
constexpr int64_t JCLTIME_MOD_YEAR      = 100ll * JCLTIME_MOD_MONTH;
constexpr int64_t JCLTIME_TM_BASE       = JCLTIME_MOD_YEAR * 1900ll + JCLTIME_MOD_MONTH;

#define _countof(arr) static_cast<int>(sizeof(arr)/sizeof(arr[0]))

enum Period
{
    PERIOD_NONE = -1,
    PERIOD_MIN5,
    PERIOD_MIN15,
    PERIOD_MIN30,
    PERIOD_MIN60,
    PERIOD_DAY,
    PERIOD_WEEK,
    PERIOD_MONTH,
    PERIOD_MIN1,
    PERIOD_MINN,
    PERIOD_DAYN,
    PERIOD_SEASON,
    PERIOD_YEAR,
    PERIOD_MIN120,
    PERIOD_ZST = 21,
};

#pragma pack(push,1)
struct tagReqHeader
{
    uint32_t    dwcrc;
    uint8_t     Version;
    uint8_t     Compressed;
    uint8_t     Encrypted;
    uint8_t     Reserved;
    uint32_t    cookie;
    uint32_t    ReqNo;
    uint32_t    GroupId;
    uint32_t    PacketLen;
    uint32_t    RawLen;
    int8_t      Priority;
};

struct tagAnsHeader
{
    uint32_t    dwcrc;
    int32_t     Separator;
    uint32_t    PacketLen;
    uint32_t    RawLen;
    uint8_t     Version;
    uint8_t     Compressed;
    uint8_t     Encrypted;
    uint8_t     Reserved;
    uint32_t    cookie;
    uint32_t    ReqNo;
    uint32_t    GroupId;
    int8_t      Priority;
    int32_t     req;
};
#pragma pack(pop)

//软件行情服务器配置
struct QuoteServerInfo
{
    std::string server_ip;
    std::string name;
    int port, quote_type;
};

union StockCodeType
{
    struct flag_t
    {
        uint64_t reserved : 1;                //保留位

        uint64_t SZAG : 1;                    //A股
        uint64_t SZZS : 1;                    //指数
        uint64_t SZZX : 1;                    //中小企业板
        uint64_t SZCY : 1;                    //创业板
        uint64_t SZBG : 1;                    //B股
        uint64_t SZJJ_LOF : 1;                //开放式基金(LOF基金)
        uint64_t SZJJ_LOFFJ : 1;            //分级基金
        uint64_t SZJJ_ETF : 1;                //ETF基金
        uint64_t SZJJ_FBS : 1;                //传统封闭式证券投资基金
        uint64_t SZBOND_GZQ : 1;            //国债
        uint64_t SZBOND_TXGZQ : 1;            //贴现国债
        uint64_t SZBOND_DFZQ : 1;            //地方债
        uint64_t SZBOND_ZFZCZQ : 1;            //政府支持债券
        uint64_t SZBOND_GSZQ : 1;            //公司债
        uint64_t SZBOND_ZQGSDQGSZQ : 1;        //证券公司短期公司债券
        uint64_t SZBOND_ZQGSCJZQ : 1;        //证券公司次级债券
        uint64_t SZBOND_FGKFXGSZQ : 1;        //非公开发行公司债券
        uint64_t SZBOND_CXPZGSZQ : 1;        //创新品种公司债券
        uint64_t SZBOND_QYZQ : 1;            //企业债
        uint64_t SZBOND_BDCTZXTQYZQ : 1;    //不动产投资信托基金
        uint64_t SZBOND_ZCZCZQ : 1;            //企业资产支持证券债券
        uint64_t SZBOND_KZHZQ : 1;            //可转换债券
        uint64_t SZBOND_CXCYKZHZQ : 1;        //创新创业可转换债券
        uint64_t SZBOND_KJHGSZQ : 1;        //可交换公司债券
        uint64_t SZBOND_FGKFXKJHGSZQ : 1;    //非公开发行可交换公司债券
        uint64_t SZBOND_KZHGSZQ : 1;        //认股权和债券分离交易的可转换公司债券
        uint64_t SZBOND_JRZQ : 1;            //政策性金融债券
        uint64_t SZQZ_SUB : 1;                //A股认购权证
        uint64_t SZQZ_PUT : 1;                //A股认沽权证
        uint64_t SZQZ_BG : 1;                //B股权证
        uint64_t SZQZ_CYB : 1;                //创业板权证
        uint64_t SZQZ_AGPG : 1;                //A股配股权证
        uint64_t SZHG : 1;                    //债券回购
        uint64_t SZPUB_AGZF : 1;            //A股增发
        uint64_t SZPUB_CYB : 1;                //创业板增发
        uint64_t SZYXG : 1;                    //优先股
        uint64_t SZWLTP : 1;                //网络投票
        uint64_t SZMMJHGS : 1;                //投资者服务密码激活/挂失处理

        uint64_t SHZS : 1;                    //上证指数系列、中证指数系列
        uint64_t SHBOND_GZ : 1;                //国债
        uint64_t SHBOND_ZCXYHJRZQ : 1;        //政策性银行金融债
        uint64_t SHBOND_TXGZ : 1;            //记账式贴现国债
        uint64_t SHZYQ_GZZYSHG : 1;            //国债质押式回购质押券出入库
        uint64_t SHHG_BOND : 1;                //债券回售
        uint64_t SHZYQ_QYZQ : 1;            //企业债券质押券出入库
        uint64_t SHZYQ_GSZQ : 1;            //公司债券质押券出入库
        uint64_t SHZYQ_KFLJY_KZHGSZQ : 1;    //分离交易的可转换公司债券质押券出入库
        uint64_t SHZYQ_ZQJYXKFJJ : 1;        //债券交易型开放式指数基金质押券出入库
        uint64_t SHZYQ_KZHGSZQ : 1;            //可转换公司债券质押券出入库
        uint64_t SHZYQ_DFZQ : 1;            //地方政府债券质押券出入库
        uint64_t SHZYQ_TXGZ : 1;            //记账式贴现国债质押券出入库
        uint64_t SHZYQ_ZCXYHJRZQ : 1;        //政策性银行金融债质押券出入库
        uint64_t SHBOND_KZHGSZQ_GKFX : 1;    //上市公司公开发行可转换公司债券
        uint64_t SHBOND_KZHGSZQ_FGKFX : 1;    //上市公司非公开发行可转换公司债券
        uint64_t SHBOND_KZHGSZQ_FLJY : 1;    //分离交易的可转换公司债券
        uint64_t SHBOND_KZHGSZQ : 1;        //可转换公司债券
        uint64_t SHBOND_GSZQ : 1;            //公司债券
        uint64_t SHBOND_QYZQ : 1;            //企业债券
        uint64_t SHBOND_ZCZQ : 1;            //资产支持证券
        uint64_t SHBOND_ZXQYSMZQ : 1;        //中小企业私募债券、非公开发行公司债券
        uint64_t SHBOND_XDZCZQ : 1;            //信贷资产支持证券
        uint64_t SHBOND_DFZQ : 1;            //地方政府债券
        uint64_t SHBOND_KJHGSZQ_FGKFX : 1;    //非公开发行可交换公司债券
        uint64_t SHBOND_KJHGSZQ : 1;        //可交换公司债券
        uint64_t SHZYQ_KJHGSZQ : 1;            //可交换公司债券质押券出入库
        uint64_t SHZYQ_GKFXGSZQ : 1;        //公开发行公司债券质押券出入库
        uint64_t SHBOND_GKFXGSZQ : 1;        //公开发行公司债券交易
        uint64_t SHBOND_FGKFXGSZQ : 1;        //非公开发行公司债券
        uint64_t SHBOND_ZQGSDQZQ : 1;        //证券公司短期债券
        uint64_t SHBOND_BGCZSMZQ : 1;        //并购重组私募债券
        uint64_t SHZG_FGKFX_KJHGSZQ : 1;    //非公开发行可交换公司债券换股
        uint64_t SHZG_KZHGSZQ : 1;            //可转换公司债券转股
        uint64_t SHZG_KJHGSZQ : 1;            //可交换公司债券换股
        uint64_t SHZG_CXCYFGKFXKZHGSZQ : 1;    //创新创业公司非公开发行可转换公司债券转股
        uint64_t SHHG_GZ_XWTG : 1;            //国债回购(席位托管方式)
        uint64_t SHHG_QYZQ : 1;                //企业债回购(席位托管方式)
        uint64_t SHHG_GZMD : 1;                //国债买断式回购
        uint64_t SHHG_ZQZYSHG_ZHTG : 1;        //债券质押式回购(账户托管方式)
        uint64_t SHHG_ZQZYSBJHG : 1;        //质押式报价回购
        uint64_t SHHG_ZQZYSXYHG : 1;        //债券质押式协议回购
        uint64_t SHHG_ZQZYSSFHG : 1;        //债券质押式三方回购
        uint64_t SHQH_GZ : 1;                //国债期货(暂停交易)
        uint64_t SHYXG_GKFX : 1;            //公开发行优先股
        uint64_t SHYXG_FGKFX : 1;            //非公开发行优先股
        uint64_t SHJJ : 1;                    //基金
        uint64_t SHJJ_FBQY : 1;                //契约型封闭式基金
        uint64_t SHJJ_LOF : 1;                //上市开放式基金
        uint64_t SHJJ_LOFFJ : 1;            //上证LOF财务分级基金交易
        uint64_t SHJJ_FBCXX : 1;            //创新型封闭式证券投资基金
        uint64_t SHJJ_ETF : 1;                //交易型开放式指数证券投资基金(标的指数为沪市指数、跨市场指数或跨境指数)
        uint64_t SHJJ_ZQETF : 1;            //债券交易型开放式指数基金
        uint64_t SHJJ_HBETF : 1;            //交易型货币市场基金
        uint64_t SHJJ_SPETF : 1;            //商品交易型开放式证券投资基金
        uint64_t SHPUB_KFSJJSGSH : 1;        //开放式基金申赎
        uint64_t SHPUB_KFSJJRG : 1;            //开放式基金认购
        uint64_t SHPUB_KFSJJTG : 1;            //开放式基金跨市场转托管
        uint64_t SHPUB_KFSJJFH : 1;            //开放式基金分红
        uint64_t SHPUB_KFSJJZH : 1;            //开放式基金基金转换
        uint64_t SHQZ : 1;                    //权证(含股改权证、公司权证)
        uint64_t SHQZXQ : 1;                //权证行权
        uint64_t SHAG : 1;                    //A股
        uint64_t SHKCB : 1;                    //A股(科创板)
        uint64_t SHCTPZ : 1;                //存托凭证
        uint64_t SHPUB_PG : 1;                //配股
        uint64_t SHPUB_ZPG : 1;                //转配股
        uint64_t SHPUB_ZGGPG : 1;            //职工股配股
        uint64_t SHPUB_PS : 1;                //配售
        uint64_t SHPUB_CGPZQ : 1;            //持股配债
        uint64_t SHPUB_JJKM : 1;            //基金扩募
        uint64_t SHYYSG : 1;                //要约收购、现金选择权(其中706600-706999用于科创板公司要约收购、现金选择权)
        uint64_t SHPUB_SZPSPG : 1;            //按市值配售配股
        uint64_t SHPUB_SGZF : 1;            //网上按市值申购或增发
        uint64_t SHPUB_CGZF : 1;            //持股增发
        uint64_t SHPUB_SGKZFK : 1;            //申购款或增发款
        uint64_t SHPUB_JJSG : 1;            //基金申购
        uint64_t SHPUB_SGZFPH : 1;            //网上按市值申购或增发配号
        uint64_t SHPUB_SZPS : 1;            //按市值配售
        uint64_t SHWLTP_AG : 1;                //网络投票
        uint64_t SHPUB_SZPSSG : 1;            //按市值配售申购
        uint64_t SHPUB_KZHGSZQSG : 1;        //可转换公司债券申购
        uint64_t SHPUB_KZHGSZQSGK : 1;        //可转换公司债券申购款
        uint64_t SHPUB_KZHGSZQPH : 1;        //可转换公司债券配号
        uint64_t SHPUB_JJSGK : 1;            //基金申购款
        uint64_t SHPUB_JJSGPH : 1;            //基金申购配号
        uint64_t SHPUB_SZPSPH : 1;            //按市值配售配号
        uint64_t SHPUB_GZCX : 1;            //国债承销发行
        uint64_t SHPUB_GZ : 1;                //国债分销
        uint64_t SHPUB_ZCXYHJRZQ : 1;        //政策性银行金融债券分销
        uint64_t SHPUB_DFZQ : 1;            //地方政府债券网上分销
        uint64_t SHPUB_GZLVZB : 1;            //利率招标国债预发行交易
        uint64_t SHPUB_GZJGZB : 1;            //价格招标国债预发行交易
        uint64_t SHPUB_GSZQ : 1;            //公司债券及企业债分销
        uint64_t SHPUB_GKFXGSZQ : 1;        //面向合格投资者公开发行公司债券网上分销
        uint64_t SHPUB_KJHZQSG : 1;            //可交换公司债券网上发行申购(759000-759099用于可交换公司债券网上发行申购)
        uint64_t SHPUB_KJHZQPH : 1;            //可交换公司债券网上发行配号(758000-758099用于可交换公司债券网上发行配号)
        uint64_t SHPUB_GKFXYXGSG : 1;        //公开发行优先股申购
        uint64_t SHPUB_GKFXYXGPGPS : 1;        //公开发行优先股配股、配售
        uint64_t SHPUB_GKFXYXGSGK : 1;        //公开发行优先股申购款
        uint64_t SHPUB_GKFXYXGSGPH : 1;        //公开发行优先股申购配号
        uint64_t SHPUB_KCBPG : 1;            //科创板股票配股
        uint64_t SHPUB_KCBSG : 1;            //科创板股票网上申购
        uint64_t SHPUB_KCBSGPH : 1;            //科创板股票网上申购配号
        uint64_t SHPUB_KCBCTPZSG : 1;        //科创板存托凭证网上申购
        uint64_t SHPUB_KCBCTPZSGPH : 1;        //科创板存托凭证网上申购配号
        uint64_t SHZJQDKZ : 1;                //799970 资金前端控制自设额度应急调整代码
        uint64_t SHRZRQ_YQHZ : 1;            //799981 余券划转
        uint64_t SHRZRQ_HQHZ : 1;            //799982 还券划转
        uint64_t SHRZRQ_DBWHZ : 1;            //799983 担保物划转
        uint64_t SHRZRQ_QYHZ : 1;            //799984 券源划转
        uint64_t SHWLTP_MMFW : 1;            //799988 A股网络投票密码服务
        uint64_t SHTZZSFRZ : 1;                //799991 通过交易报盘方式为投资者办理中国结算网络服务身份认证
        uint64_t SHRZRQ_SBJS : 1;            //799993 证券金融公司转融通申报结束提醒
        uint64_t SHHGZDCX : 1;                //799996 回购指定撤销
        uint64_t SHHGZD : 1;                //799997 回购指定
        uint64_t SHZDJYCX : 1;                //799998 撤销指定
        uint64_t SHZDJY : 1;                //799999 指定交易
        uint64_t SHBZQ : 1;                    //标准券(888880代码为新标准券，用于债券回购转换成标准券)
        uint64_t SHBG : 1;                    //B股
        uint64_t SHWLTP_BG : 1;                //网络投票(B股)
        uint64_t SHWLTP_BGMMFW : 1;            //B股网络投票密码服务(现仅用939988)
        uint64_t SHBGQZ : 1;                //B股配股权证
        uint64_t SHBLOCK : 1;                //板块指数
        uint64_t SHAMV : 1;                    //AMV指数

        //海峡交易所
        uint64_t HXYSZB : 1;                //艺术主板
        uint64_t HXYSXB : 1;                //艺术新版
        uint64_t HXYPSC : 1;                //邮票收藏
        uint64_t HXQBSC : 1;                //钱币收藏
        uint64_t HXPSJK : 1;                //配售转让
        uint64_t HXZS : 1;                    //海峡艺术品指数
        uint64_t HXCCQB : 1;                //茶产权版

        //广州茶叶
        uint64_t TEAZS : 1;                    //茶叶指数
        uint64_t TEAGOODS : 1;                //茶叶商品
    }u;
    uint64_t type[(sizeof(flag_t) - 1) / sizeof(uint64_t) + 1];

    bool operator & (const StockCodeType& other) const
    {
        for (int i = 0; i < _countof(type); i++)
        {
            if (type[i] & other.type[i]) return true;
        }
        return false;
    }

    bool operator == (const StockCodeType& other) const
    {
        for (int i = 0; i < _countof(type); i++)
        {
            if (type[i] != other.type[i]) return false;
        }
        return true;
    }

    operator bool() const
    {
        for (auto t : type)
        {
            if (t) return true;
        }
        return false;
    }

    bool operator ! () const
    {
        for (auto t : type)
        {
            if (t) return false;
        }
        return true;
    }

    const static StockCodeType all;
};


//搜索系数
struct tagCodeWithRelate
{
    StkInfoNew* code;
    long relate;
    
    bool operator < (const tagCodeWithRelate& other) const
    {
        if (code.setcode == other.code.setcode)
        {
            if ([code.code isEqualToString:other.code.code])
            {
                return relate < other.relate;
            }
            return [code.code compare:other.code.code] == NSOrderedAscending;
        }
        return code.setcode < other.code.setcode;
    }
};
