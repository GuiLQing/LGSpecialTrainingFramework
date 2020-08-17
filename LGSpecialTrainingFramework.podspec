Pod::Spec.new do |s|
  s.name             = 'LGSpecialTrainingFramework'
  s.version          = '0.1.9'
  s.summary          = 'A short description of LGSpecialTrainingFramework.'

  s.description      = <<-DESC
TODO: Add long description of the pod here.
                       DESC

  s.homepage         = 'https://github.com/GuiLQing/LGSpecialTrainingFramework'
  s.license          = { :type => 'MIT', :file => 'LICENSE' }
  s.author           = { 'GuiLQing' => 'gui950823@126.com' }
  s.source           = { :git => 'https://github.com/GuiLQing/LGSpecialTrainingFramework.git', :tag => s.version.to_s }

  s.ios.deployment_target = '9.0'
  
  #需要包含的源文件
  s.source_files = 'LGSpecialTrainingFramework/Classes/LGSpecialTrainingFramework.framework/Headers/*.{h}'
  
  #你的SDK路径
  s.vendored_frameworks = 'LGSpecialTrainingFramework/Classes/LGSpecialTrainingFramework.framework'
  
  s.resources = 'LGSpecialTrainingFramework/Assets/LGSpecialTrainingFramework.bundle'
  
  s.dependency 'AFNetworking','3.2.1'
  s.dependency 'Masonry'
  s.dependency 'JSONModel'
  s.dependency 'SDWebImage'
  s.dependency 'MJExtension'
  s.dependency 'Reachability'
  s.dependency 'ReactiveObjC'
  s.dependency 'MJRefresh'
  s.dependency 'XMLDictionary'
  s.dependency 'MBProgressHUD', '1.1.0'
  s.dependency 'MarqueeLabel','3.2.0'
  s.dependency 'Realm'
  
  s.dependency 'YJTaskMark'
  s.dependency 'YJTaskModule'
  s.dependency 'YJResizableSplitView'
  s.dependency 'YJPresentAnimation'
  s.dependency 'YJExtensions'
  s.dependency 'YJNetManager'
  s.dependency 'LGAlertHUD'
  s.dependency 'YJUtils'
  s.dependency 'YJImageBrowser'

  s.dependency 'SGTools'
  s.dependency 'LGBundle'
end
