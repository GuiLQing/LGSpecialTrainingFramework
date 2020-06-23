//
//  STFTrainingPaperModel.h
//  LGSpecialTrainingFramework
//
//  Created by lancoo on 2020/4/3.
//  Copyright © 2020 SG. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <MJExtension/MJExtension.h>

@class
STFTrainingPaperModel,
TFTrainingListenWordListModel,
STFTrainingListenWordModel,
STFTrainingBigTopicModel,
STFTrainingSmallTopicModel,
STFTrainingCorrectMistakesModel;

/// 试卷模型
@interface STFTrainingPaperModel : NSObject

/// 训练包状态：-1：训练未过关，0：未训练；1：训练过关；2:训练中断
@property (nonatomic, strong) NSNumber *BagStatus;
/// 训练包编号
@property (nonatomic, copy) NSString *BagNum;
/// 总的题目数量(小题)
@property (nonatomic, strong) NSNumber *BagTotalNum;
/// 预计时长
@property (nonatomic, copy) NSString *TimeSpance;
/// 训练包类型，listen：听力过关训练；speak：口语过关训练；read：阅读过关训练；write：写作过关训练；
@property (nonatomic, copy) NSString *TrainBagType;

#pragma mark - 需要提交上传的字段

/** 训练包名称编码：
 听录音选图片(E31)        听句子选答语(E37)         词汇听写(VD)                听长对话(E3)
 听短对话(E2)                 听力填空(CS)                  听力选择(LC)                听短文(CE4)
 短文听写(W19)              阅读选择(D28)                 完形选择(C)                 阅读填空(Q)
 短文匹配(m17)              阅读综合(k)                      阅读简答(X)                 词汇匹配(m15)
 选词填空(N20)              翻译填空(N22)                  连词成句(V)                 看图写句子(d)
 书面表达(f36)               句子英译中(g40)                短文填空(N23)            改错题(U)
 段落总结(f35)               句子填空(N21)                   篇章英译中(g39)          篇章中译英(g41)
 */
@property (nonatomic, copy) NSString *BagNameNumber;
/// 最高积分 integer
@property (nonatomic, strong) NSNumber *HighestPoints;
/// 训练包所属阶段，初级(junior)/中级(intermediate)/高级(advanced)
@property (nonatomic, copy) NSString *TrainBagStage;
/// 平均训练难度
@property (nonatomic, strong) NSNumber *AVGHVAL;
/// 学科编码
@property (nonatomic, copy) NSString *SubjectID;
/// 听力词汇训练包集合
@property (nonatomic, strong) TFTrainingListenWordListModel *LTBLists;
/// 其它训练包集合
@property (nonatomic, strong) NSArray<STFTrainingBigTopicModel *> *TrainBagList;
/// 训练包导语(2020-6-2新增)
@property (nonatomic, copy) NSString *ChTBInt;

#pragma mark - 需另外赋值的字段

/// 安全码
@property (nonatomic, copy) NSString *SecCode;
/// 用户ID
@property (nonatomic, copy) NSString *UserID;
/// 操作端：PC端：CONTEXT01；Web端：CONTEXT02；Android端：CONTEXT03；IOS端：CONTEXT04；学校PC端：CONTEXT05；个人PC端：CONTEXT06；
@property (nonatomic, copy) NSString *CONTEXT;
/// 训练系统
@property (nonatomic, copy) NSString *TrainSystem;
/// 训练阶段：初级(junior)/中级(intermediate)/高级(advanced)
@property (nonatomic, copy) NSString *TrainStage;
/// 训练时长 integer
@property (nonatomic, strong) NSNumber *TrainTime;
/// 建议训练时长 integer
@property (nonatomic, strong) NSNumber *RecomTrainTime;
/// 结束训练时间
@property (nonatomic, copy) NSString *EndDate;
/// 中断位置(-1表示完成，0表示未做，其他的表示页数) integer
@property (nonatomic, strong) NSNumber *LastProgress;
/// 小题数量 integer
@property (nonatomic, strong) NSNumber *BagNumber;

- (void)parsePaperModelWithAnswerModel:(STFTrainingPaperModel *)answer;

- (NSArray *)taskCarkModelArray;

@property (nonatomic, assign) NSInteger currentBigTopicIndex;

@property (nonatomic, assign) NSInteger currentSmallTopicIndex;


@end

@interface TFTrainingListenWordListModel : NSObject

/// 是否有本地数据缓存
@property (nonatomic, assign) BOOL isLocalCached;

#pragma mark - 需要提交上传的字段

/// 题目导语
@property (nonatomic, copy) NSString *TopicPintro;
/// 体裁编号
@property (nonatomic, copy) NSString *TopicGenreCode;
/// 听力词汇正确数量（特殊,专供不区分大小题使用）
@property (nonatomic, strong) NSNumber *CorrectNum;
/// 听力词汇错误数量（特殊,专供不区分大小题使用）
@property (nonatomic, strong) NSNumber *ErrorNum;
/// 听力词汇训练包集合
@property (nonatomic, strong) NSArray<STFTrainingListenWordModel *> *LTBAnser;

@end

/// 听写单词模型
@interface STFTrainingListenWordModel : NSObject

/// 知识点类型
@property (nonatomic, copy) NSString *KlgType;
/// 小题数
@property (nonatomic, strong) NSNumber *UnitNum;
/// 难度系数(自定义：A：0.8，B:0.6，C:0.4，D:0.2)
@property (nonatomic, strong) NSNumber *HVAL;
/// 知识点来源编码
@property (nonatomic, copy) NSString *ResourceCode;
/// 音频路径
@property (nonatomic, copy) NSString *Voice;

#pragma mark - 需要提交上传的字段

/// 单词在训练包中的下标
@property (nonatomic, copy) NSString *KnowledgeIndex;
/// 词汇代码
@property (nonatomic, copy) NSString *KnowledgeCode;
/// 词汇名称（词汇/答案）
@property (nonatomic, copy) NSString *Knowledge;
/// 小题分数 decimal number
@property (nonatomic, strong) NSNumber *QuesScore;
/// 小题作答答案(学生)
@property (nonatomic, copy) NSString *AnswerStr;
/// 学生得分 decimal number
@property (nonatomic, strong) NSNumber *StuScore;
/// 解释(中文翻译)
@property (nonatomic, copy) NSString *Explain;
/// 单词音标
@property (nonatomic, copy) NSString *Phonetic;

/// 作答键盘数据保存，用于恢复作答时回显
@property (nonatomic, strong) NSArray *defaultKeyBoards;
@property (nonatomic, strong) NSArray *selectedKeyBoards;

- (NSString *)knowledgeVoice;

@end

/// 大题模型
@interface STFTrainingBigTopicModel : NSObject

/// 资源库题目ID - 识别变化可能导致改变
@property (nonatomic, copy) NSString *ResCode;
/// 教学中心组装的大题索引
@property (nonatomic, strong) NSNumber *TopicIndexEdu;
/// 大题序号
@property (nonatomic, strong) NSNumber *Index;
/// 题型名称
@property (nonatomic, copy) NSString *TopicTypeName;
/// 其它题型名称
@property (nonatomic, copy) NSString *TopicTypeOtherName;
/// 体裁名称
@property (nonatomic, copy) NSString *TopicGenreName;
/// 主要知识点
@property (nonatomic, copy) NSString *MainKlg;
/// 主要知识点编码
@property (nonatomic, copy) NSString *MainKnText;
/// 全部知识点
@property (nonatomic, copy) NSString *ImportantKlg;
/// 全部知识点编码
@property (nonatomic, copy) NSString *ImporKnText;
/// 来源
@property (nonatomic, copy) NSString *LibCode;
/// 题型
@property (nonatomic, copy) NSString *ResType;
/// 主题关键词编码
@property (nonatomic, copy) NSString *ThemeKeywordCode;
/// 主题关键词名称
@property (nonatomic, copy) NSString *ThemeKeywordText;

@property (nonatomic, copy) NSString *UpperKnlgCode;

@property (nonatomic, copy) NSString *UpperKnlgText;
/// 主题知识点
@property (nonatomic, copy) NSString *ThemeCode;

@property (nonatomic, copy) NSString *ThemeText;

@property (nonatomic, copy) NSString *Import;

@property (nonatomic, copy) NSString *Main;
/// 题目导语
@property (nonatomic, copy) NSString *TopicPintro;
/// 题目导语音频
@property (nonatomic, copy) NSString *TopicPintroMidea;
/// 听力题表征听力材料
@property (nonatomic, copy) NSString *TopicArticle;
/// 听力题表征听力音频
@property (nonatomic, copy) NSString *TopicArticleAudio;
/// 大题篇章
@property (nonatomic, copy) NSString *TopicContent;
/// PC的问题，移动端的主体
@property (nonatomic, strong) NSArray *ContentOrQues;
/// 主题
@property (nonatomic, copy) NSString *TopicTheme;
/// 难度
@property (nonatomic, strong) NSNumber *Difficulty;
/// 小题数量（答题点数量）
@property (nonatomic, strong) NSNumber *QuesCount;
/// 小题数量（实际小题数量）
@property (nonatomic, strong) NSNumber *QuesChildNum;
/// 音频
@property (nonatomic, copy) NSString *AudioResStr;
/// 图片信息
@property (nonatomic, copy) NSString *PicResStr;
/// 问题是否包含在题目中（pc页面是否左右分频作答）
@property (nonatomic, strong) NSNumber *IsQuesInContent;
/// 当前作答增加的时间（提交用）
@property (nonatomic, strong) NSNumber *AnswerTimeAdd;
/// 大题预计时间
@property (nonatomic, strong) NSNumber *QueTraceTime;
/// 各小题信息（小题）
@property (nonatomic, strong) NSArray<STFTrainingSmallTopicModel *> *QuesOri;
/// 改错题拆分结构
@property (nonatomic, strong) STFTrainingCorrectMistakesModel *GCQues;
/// 听说作业ftp信息
@property (nonatomic, copy) NSString *ftpPre;
/// 当判定匹配题不显示选项时，此字段存储所有选项
@property (nonatomic, copy) NSString *TopicOption;
/// 难度系数
@property (nonatomic, strong) NSNumber *HVAL;
/// 资料名称
@property (nonatomic, copy) NSString *ResName;

#pragma mark - 需要提交上传的字段

/// 资源库GUID - 唯一
@property (nonatomic, copy) NSString *ResGuid;
/// 正确的题数 integer
@property (nonatomic, strong) NSNumber *CorrectNum;
/// 错误的题数 integer
@property (nonatomic, strong) NSNumber *ErrorNum;
/// 大题ID
@property (nonatomic, copy) NSString *TopicID;
/// 大题总分 decimal number
@property (nonatomic, strong) NSNumber *TopicScore;
/// 作答时间(用户作答) integer
@property (nonatomic, strong) NSNumber *AnswerTime;
/// 题型ID
@property (nonatomic, copy) NSString *TopicTypeID;
/// 体裁编号
@property (nonatomic, copy) NSString *TopicGenreCode;
/// 各小题信息（答题点）
@property (nonatomic, strong) NSArray<STFTrainingSmallTopicModel *> *Queses;

@end

/// 小题模型
@interface STFTrainingSmallTopicModel : NSObject

/// 原选项顺序
@property (nonatomic, copy) NSString *MappingData;
/// 大题ID
@property (nonatomic, copy) NSString *TopicID;
/// 整份试卷第几题
@property (nonatomic, strong) NSNumber *PaperIndex;
/// 整份试卷第几题
@property (nonatomic, strong) NSNumber *PaperIndexOri;
/// 是否是互评
@property (nonatomic, strong) NSNumber *IsHpTimu;
/// 试题音频
@property (nonatomic, copy) NSString *QuesAudio;
/// 答案解析
@property (nonatomic, copy) NSString *QuesAnalysis;
/// 选项A、B、C
@property (nonatomic, strong) NSArray *OptionKeyList;
/// 选项A、B、C的内容
@property (nonatomic, strong) NSArray *OptionContentList;
/// 图片list
@property (nonatomic, strong) NSArray *AnswerImgUrlList;
/// 互评得分
@property (nonatomic, strong) NSNumber *HpScore;
/// 是否互评
@property (nonatomic, strong) NSNumber *IsHpQues;
/// 学生作答得分
@property (nonatomic, strong) NSNumber *AnswerScore;
/// 评论
@property (nonatomic, copy) NSString *Comment;
/// 词汇
@property (nonatomic, copy) NSString *WordRichScoreStr;
/// 语法层次
@property (nonatomic, copy) NSString *YuFaCentciScoreStr;
/// 主题
@property (nonatomic, copy) NSString *ThemeScoreStr;
/// 句型
@property (nonatomic, copy) NSString *SentenceScoreStr;
/// 词汇
@property (nonatomic, copy) NSString *WordRichMarkScoreStr;
/// 语法层次
@property (nonatomic, copy) NSString *YuFaCentciMarkScoreStr;
/// 主题
@property (nonatomic, copy) NSString *ThemeMarkScoreStr;
/// 句型
@property (nonatomic, copy) NSString *SentenceMarkScoreStr;
/// 是否隐藏答案
@property (nonatomic, strong) NSNumber *QuesAnalysisHidden;
/// 是否隐藏答案
@property (nonatomic, strong) NSNumber *QuesAnswerHidden;

#pragma mark - 需要提交上传的字段

/// 第几小题 integer
@property (nonatomic, strong) NSNumber *Index;
/// 第几小题（组卷原始值）
@property (nonatomic, copy) NSString *IndexOri;
/// 小题分数 decimal number
@property (nonatomic, strong) NSNumber *QuesScore;
/// 学生得分 decimal number
@property (nonatomic, strong) NSNumber *StuScore;
/// 作答模式 integer
@property (nonatomic, strong) NSNumber *AnswerType;
/// 答案
@property (nonatomic, copy) NSString *QuesAnswer;
/// 小题作答答案(学生)
@property (nonatomic, copy) NSString *AnswerStr;
/// 阅读选择中，精读题和泛读题的编号
@property (nonatomic, copy) NSString *TypeTextCode;
/// 小题题干数组
@property (nonatomic, strong) NSArray *QuesAskList;
/// 小题题干
@property (nonatomic, copy) NSString *QuesAsk;

@end

@class
STFTrainingCorrectMistakesGenreInfoModel,
STFTrainingCorrectMistakesTextInfoModel,
STFTrainingCorrectMistakesAnswerInfoModel,
STFTrainingCorrectMistakesAnswerAreaModel;

/// 改错题模型
@interface STFTrainingCorrectMistakesModel : NSObject

/// 体裁信息
@property (nonatomic, strong) STFTrainingCorrectMistakesGenreInfoModel *GenreInfo;
/// 改错题原文信息
@property (nonatomic, copy) NSString *QuesBrief;
/// 改错题标准答案
@property (nonatomic, copy) NSString *QuesAnswer;
/// 处理后的改错题原文信息
@property (nonatomic, copy) NSString *QuesBody;
/// 数字化后的原文信息
@property (nonatomic, strong) NSArray<STFTrainingCorrectMistakesTextInfoModel *> *ModelTextInfoList;
/// 数字化后的答案信息
@property (nonatomic, strong) NSArray<STFTrainingCorrectMistakesAnswerInfoModel *> *ModelAnswerInfoList;
/// 改错题的作答区域
@property (nonatomic, strong) NSArray<STFTrainingCorrectMistakesAnswerAreaModel *> *ModelAnswerAreaList;
/// 文章的导语信息
@property (nonatomic, copy) NSString *QuesLeaderContent;

@end

@interface STFTrainingCorrectMistakesGenreInfoModel : NSObject

/// 体裁ID
@property (nonatomic, copy) NSString *GenreID;
/// 体裁名称
@property (nonatomic, copy) NSString *GenreName;
/// 体裁类型
@property (nonatomic, copy) NSString *GenreType;

@end

@interface STFTrainingCorrectMistakesTextInfoModel : NSObject

/// 单词在原文中的序号
@property (nonatomic, strong) NSNumber *Index;
/// 词汇或标点符号
@property (nonatomic, copy) NSString *Text;

@end

@interface STFTrainingCorrectMistakesAnswerInfoModel : NSObject

/// 答案的序号
@property (nonatomic, strong) NSNumber *Index;
/// 答案内容
@property (nonatomic, copy) NSString *Answer;

@end

@interface STFTrainingCorrectMistakesAnswerAreaModel : NSObject

/// 作答区的序号
@property (nonatomic, strong) NSNumber *Index;
/// 作答区的标号
@property (nonatomic, copy) NSString *AnswerArea;

@end
