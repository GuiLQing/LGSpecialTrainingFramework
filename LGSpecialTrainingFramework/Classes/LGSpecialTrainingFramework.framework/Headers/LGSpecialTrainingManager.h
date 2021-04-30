//
//  LGSpecialTrainingManager.h
//  LGSpecialTrainingFramework
//
//  Created by lancoo on 2020/3/23.
//  Copyright © 2020 SG. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface LGSpecialTrainingManager : NSObject

+ (LGSpecialTrainingManager *)defaultManager;

/// 用户ID
@property (nonatomic, copy) NSString *userID;
/// 用户名
@property (nonatomic, copy) NSString *userName;
/// 用户类型
@property (nonatomic, assign) NSInteger userType;
/// 学习阶段
@property (nonatomic, copy) NSString *studyLevel;
/// 自学基础服务器地址
@property (nonatomic, copy) NSString *freeStudyBaseUrl;
/// 英语专业化过关训练基础URL
@property (nonatomic, copy) NSString *specialTrainingBaseUrl;

@property (nonatomic, assign) BOOL isAutoFillAnswer;

#pragma mark - 数据推送字段

/** 用户登录令牌 */
@property (nonatomic, copy) NSString *Token;
/// 用户头像
@property (nonatomic, copy) NSString *PhotoPath;
/** 学科ID */
@property (nonatomic, copy) NSString *SubjectID;
/** 学科名称 */
@property (nonatomic, copy) NSString *SubjectName;
/** 课程ID */
@property (nonatomic, copy) NSString *CourseNO;
/** 课程名称 */
@property (nonatomic, copy) NSString *CourseName;
/** 班级ID */
@property (nonatomic, copy) NSString *ClassID;
/** 班级名称 */
@property (nonatomic, copy) NSString *ClassName;
/** 年级ID */
@property (nonatomic, copy) NSString *GradeID;
/** 年级名称 */
@property (nonatomic, copy) NSString *GradeName;
/** 学校ID */
@property (nonatomic, copy) NSString *SchoolID;
/** 学校名称 */
@property (nonatomic, copy) NSString *SchoolName;
/// 学年学期
@property (nonatomic, copy) NSString *Term;

#pragma mark - 知识点课件对接

/** 跳转知识点学习课件详细信息 */
@property (nonatomic, copy) void (^ _Nullable jumpToLGKnowledgeBlock) (UIViewController *fromController,NSString *klgCode, BOOL onlyKlgCark);
/** 知识点学习课件弹框 */
@property (nonatomic, copy) void (^ _Nullable jumpToLGKnowledgeAlertBlock) (UIViewController *fromController, NSString *klgCode, void (^ _Nullable addStudyBlock) (void));

#pragma mark - 模块跳转

/// 跳转专业化过关训练首页
@property (nonatomic, copy, readonly) void (^presentSpecialTrainingHomeViewController)(UIViewController *fromController);

@end

NS_ASSUME_NONNULL_END
