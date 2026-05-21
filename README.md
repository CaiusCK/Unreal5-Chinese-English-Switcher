# Chinese English Switcher / UE 中英文一键切换插件

Unreal Engine 编辑器插件，用于在英文和简体中文之间一键切换编辑器语言。

## 安装

1. 将本文件夹复制到你的 Unreal 项目中：

   `YourProject/Plugins/ChineseEnglishSwitcher`

2. 如果项目是 C++ 项目，重新生成项目文件。
3. 编译项目，或直接用 Unreal Editor 打开项目让编辑器编译插件。
4. 如果插件没有自动启用，在 **Edit > Plugins** 中启用 **Chinese English Switcher**。

建议插件文件夹使用英文路径，例如 `YourProject/Plugins/ChineseEnglishSwitcher`。如果放在中文路径下，部分 Windows + UnrealBuildTool 环境可能只弹出 `could not be compiled`，但不显示真实编译错误。

## 使用

- 打开 **Tools > Language**。
- 选择 **Toggle Chinese / English**、**Switch to English** 或 **Switch to Chinese**。
- Level Editor 顶部工具栏的播放按钮附近会出现一个地球图标按钮，用于一键切换。

切换后，大部分文本会立即跟随 Unreal 的国际化系统更新。部分编辑器文本可能被缓存，需要重启 Unreal Editor 才能完全生效。

## 编译失败排查

如果 Unreal 只弹出 `could not be compiled`：

1. 确认插件目录是英文路径：`YourProject/Plugins/ChineseEnglishSwitcher`。
2. 删除项目下的 `Binaries`、`Intermediate`，再重新生成项目文件。
3. 打开项目的 `Saved/Logs/YourProject.log`，搜索第一条 `error C` 或 `error CS`，那一行才是真正原因。

## 目标版本

该插件是编辑器专用 C++ 模块，面向 UE5.x 项目，包括 UE5.7 风格项目结构。

## License

MIT License. See `LICENSE` for details.
