
内容说明
---------------------------------------------------------------------------------------
| Chapter  |  Subject               |  Description               |
|----------|------------------------|----------------------------|
| CH12     |  Gameplay Abilities    |没太多有价值的东西，只是里面对数据表的使用有点新鲜 |



使用 Slate 的正确姿势
---------------------------------------------------------------------------------------
在 [ProjectName].Build.cs中加入  
> PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });  

  *不加入会有找不到方法的链接错误*

就可以使用了：
<pre>
TSharedRef<SVerticalBox> widget = SNew(SVerticalBox)
  + SVerticalBox::Slot()
  .HAlign(HAlign_Center)
  .VAlign(VAlign_Center)
  [
    SNew(SButton)
    .Content()
    [
      SNew(STextBlock)
      .Text(FText::FromString(TEXT("Test button")))
    ]
  ];

GEngine->GameViewport->AddViewportWidgetForPlayer( GetLocalPlayer(), widget, 1);
</pre>



CH9
---------------------------------------------------------------------------------------
**UCustomButtonWidget**  
UCustomButtonWidget 派生自 UWidget, 由C++写实现，可以在UMG中拖放到User Widget中使用。



Unreal Engine 4 Scripting with C++ Cookbook
---------------------------------------------------------------------------------------
This is the code repository for [Unreal Engine 4 Scripting with C++ Cookbook](https://www.packtpub.com/game-development/unreal-engine-4-scripting-c-cookbook?utm_source=Github&utm_medium=Repository&utm_campaign=9781785885549), published by Packt. It contains all the supporting project files necessary to work through the book from start to finish.


Related Products
---------------------------------------------------------------------------------------
* [Unreal Engine 4.X By Example](https://www.packtpub.com/game-development/unreal-engine-4x-example?utm_source=Github&utm_medium=Repository&utm_campaign=9781785885532)

* [Learning C++ by Creating Games with UE4](https://www.packtpub.com/game-development/learning-c-creating-games-ue4?utm_source=Github&utm_medium=Repository&utm_campaign=9781784396572)

* [UnrealScript Game Programming Cookbook](https://www.packtpub.com/game-development/unrealscript-game-programming-cookbook?utm_source=Github&utm_medium=Repository&utm_campaign=9781849695565)
###Suggestions and Feedback
[Click here](https://docs.google.com/forms/d/e/1FAIpQLSe5qwunkGf6PUvzPirPDtuy1Du5Rlzew23UBp2S-P3wB-GcwQ/viewform) if you have any feedback or suggestions.
