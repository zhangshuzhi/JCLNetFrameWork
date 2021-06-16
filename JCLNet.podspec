#
#  Be sure to run `pod spec lint jclframework.podspec.podspec' to ensure this is a
#  valid spec and to remove all comments including this before submitting the spec.
#
#  To learn more about Podspec attributes see https://guides.cocoapods.org/syntax/podspec.html
#  To see working Podspecs in the CocoaPods repo see https://github.com/CocoaPods/Specs/
#

Pod::Spec.new do |spec|

  # ―――  Spec Metadata  ―――――――――――――――――――――――――――――――――――――――――――――――――――――――――― #
  #
  #  These will help people to find your library, and whilst it
  #  can feel like a chore to fill in it's definitely to your advantage. The
  #  summary should be tweet-length, and the description more in depth.
  #

  spec.name         = "JCLNet"
  spec.version      = "1.0.0"
  spec.summary      = "request SDK"
  spec.description  = <<-DESC
	GMUnite for gama games developer.GMUnite for gama games developer.
                   DESC

  spec.homepage     = "https://github.com/zhangshuzhi/JCLNetFrameWork.git"
  spec.license       = { :type => "MIT", :file => "LICENSE" }
  spec.author             = { "zsz" => "541957412@qq.com" }
  spec.platform     = :ios  
  spec.ios.deployment_target = "11.0"
  spec.source       = { :git => "https://github.com/zhangshuzhi/JCLNetFrameWork.git", :tag => "#{spec.version}" }
  spec.ios.vendored_frameworks = 'Framework/JCLStockConnect.framework'#SDK相对本文件路径
  spec.frameworks = "UIKit", "Foundation"#SDK依赖的系统库文件  
  spec.pod_target_xcconfig = { 'VALID_ARCHS' => 'x86_64 armv7 arm64'}#支持架构配置
end
