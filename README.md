Seamless Framework (v1.0.0)
==================================


Requirements
----------------------------------

- Minimum deployment target

  - iOS 6.0

- Auto Reference Counting (ARC)

  - Yes, it requires ARC.

- Frameworks

  - As of "-ObjC" flag must be defined, no need to link additional binary libraries (frameworks)



Installation
----------------------------------

### Drag and drop

  1. Drag "Seamless.embeddedframework" into "Frameworks" folder.
     If folder is not visible at the left side of XCode window, you could reveal navigation bar with (command + shift + j) keyboard shortcut and find it under your project. A dialog for file adding options will appear


![Alt text](/ReadmeAssets/DragAndDrop/6.png "Drag & drop Seamless.embeddedframework")

![Alt text](/ReadmeAssets/DragAndDrop/7.png "File adding options setup dialog")


  . On dialog;

  * Create groups for any added folders and

      ![Alt text](/ReadmeAssets/DragAndDrop/dragsetupfolders.png "Select 'Create groups for any added folders and'")



  * "YourProjectName" at "Add to targets" section.

      ![Alt text](/ReadmeAssets/DragAndDrop/dragsetuptarget.png "Select <YourProjectName> at "Add to targets" section.")


  must be selected.

  If cloned Woodo's git repository, it is recommended, but not mandatory, to un-check (de-select) "Copy items into destination group's folder (if needed)", as keeping repository up-to-date would be much more easier.

  2. Now, you have to add 'Other Linker Flags'. Click project navigator icon ![Alt text](/ReadmeAssets/Common/iconnavigator.png "Navigator icon") at upper-left corner (below run button)

    ! If unable to see project navigator, navigator might be closed. You could reveal navigation bar with (command + shift + j) keyboard shortcut.

  3. Select your project from project navigator

    ![Alt text](/ReadmeAssets/Common/selectproject.png "Select project")

  4. Select project target

    ![Alt text](/ReadmeAssets/Common/selecttarget.png "Select target")

  5. Select "Build settings" tab

     ![Alt text](/ReadmeAssets/Common/selectbuildsettings.png "Select 'Build Settings'")

  6. Search for "Other Linker Flags"

    ![Alt text](/ReadmeAssets/Common/searchotherlinkerflags.png "Search for 'Other Linker Flags'")

  7. Add "-ObjC" flag

    ![Alt text](/ReadmeAssets/Common/addflagobjc.png "Add linker flag '-ObjC'")

  , and you are done.

  *To dive in coding, see **"How to use"** section below.*


How to use
----------------------------------

### Setup

  In order to use Seamless Framework properly "AppToken" parameter need to be declared on SLManager class before usage. It is recommended to perform setup on "UIApplicationDelegate" instance's "application:application didFinishLaunchingWithOptions:." selector.

  i.e

  ```Objective-C
    - (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions
    {
      // Override point for customization after application launch.

      // ...

      [SLManager setAppToken:@"<Please contact seamless@mobilike.com for app token data>"];

      // ...

      return YES;
    }
  ```

### TableView integration

- Import required headers

  ```Objective-C
    #import <Seamless/Seamless.h>
  ```

- Declare a SLTableViewAdManager *adManager property in your view controller.

  ```Objective-C
    @property (nonatomic, strong) SLTableViewAdManager * adManager;
  ```

- In viewDidLoad; instantiate a SLTableViewAdManager, passing your tableview, data source and view controller. Data source must be NSMutableArray.

  ```Objective-C
    self.adManager = [[SLTableViewAdManager alloc] initWithTableView:self.tableView
                                                          dataSource:self.dataSource
                                                      viewController:self];
  ```
- Request ads with entity name that identifies your feeds content, category (feed contents category), and success, failure, start and finish handlers.

  ```Objective-C
     [self.adManager
     getAdsWithEntity:@"seamless-example-tableview"
     category:SLCategoryNews
     startHandler:^{
         NSLog(@"start");
     }
     finishHandler:^{
         NSLog(@"finish");
     }
     successHandler:^{
         NSLog(@"ads loaded");
     }
     failureHandler:^(NSError *error) {
         NSLog(@"%@",error);
     }];
  ```
- Add these codes into the UITableView datasource and delegate methods;

  ```Objective-C
 - (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath{

    if([self.adManager shouldShowAdAtIndexPath:indexPath]){
        return [self.adManager cellForRowAtIndexPath:indexPath];
    }

    // your stuff here
  }
  ```

  ```Objective-C
   - (CGFloat)tableView:(UITableView *)tableView heightForRowAtIndexPath:(NSIndexPath *)indexPath{

    if ([self.adManager shouldShowAdAtIndexPath:indexPath])
    {
        return [self.adManager heightForRowAtIndexPath:indexPath];
    }

    // your stuff here
   }
  ```

  ```Objective-C
  - (void)tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath{

    if([self.adManager shouldShowAdAtIndexPath:indexPath])
    {
        [self.adManager didSelectRowAtIndexPath:indexPath];
    }
    else
    {
      // your stuff here
    }
  }
  ```
### CollectionView integration

- Import required headers

  ```Objective-C
    #import <Seamless/Seamless.h>
  ```

- Declare a SLCollectionViewAdManager *adManager property in your view controller.

  ```Objective-C
    @property (nonatomic, strong) SLCollectionViewAdManager * adManager;
  ```

- In viewDidLoad; instantiate a SLCollectionViewAdManager, passing your collection view, data source and view controller. Data source must be NSMutableArray.

  ```Objective-C
    self.adManager = [[SLCollectionViewAdManager alloc] initWithCollectionView:self.collectionView
                                                                    dataSource:self.dataSource
                                                                viewController:self];
   ```
- Request ads with entity name that identifies your feeds content, category (feed contents category), and success, failure, start and finish handlers.

  ```Objective-C
     [self.adManager
     getAdsWithEntity:@"seamless-example-collectionview"
     category:SLCategoryNews
     startHandler:^{
         NSLog(@"start");
     }
     finishHandler:^{
         NSLog(@"finish");
     }
     successHandler:^{
         NSLog(@"ads loaded");
     }
     failureHandler:^(NSError *error) {
         NSLog(@"%@",error);
     }];
  ```
- Add these codes into the UICollectionView datasource and delegate methods;

  ```Objective-C
  - (UICollectionViewCell *)collectionView:(UICollectionView *)collectionView cellForItemAtIndexPath:(NSIndexPath *)indexPath{

    if([self.adManager shouldShowAdAtIndexPath:indexPath]){
        return [self.adManager cellForItemAtIndexPath:indexPath];
    }

    //your stuff here
  }
  ```

  ```Objective-C
  - (CGSize)collectionView:(UICollectionView *)collectionView layout:(UICollectionViewLayout*)collectionViewLayout sizeForItemAtIndexPath:(NSIndexPath *)indexPath{

    if([self.adManager shouldShowAdAtIndexPath:indexPath]){
        return [self.adManager sizeForItemAtIndexPath:indexPath];
    }

    //your stuff here
}
  ```

  ```Objective-C
  - (void)collectionView:(UICollectionView *)collectionView didSelectItemAtIndexPath:(NSIndexPath *)indexPath{

    if([self.adManager shouldShowAdAtIndexPath:indexPath]){
        [self.adManager didSelectItemAtIndexPath:indexPath];
    }
    else{
      //your stuff here
    }

}
  ```

### Banner integration
  - Import required headers

  ```Objective-C
    #import <Seamless/Seamless.h>
  ```

- Declare a SLAdView *adView property in your view controller.

  ```Objective-C
    @property (nonatomic, strong) SLAdView * adView;
  ```

- In viewDidLoad; instantiate a SLAdView with your entity, category, ad size and root viewcontroller.
  Set your view controller as the adView's delegate.
  Set the adView's frame and add the adView to your controller's view hierarchy.
  Finally, load an ad by sending adView the -loadAd message.

  ```Objective-C
    self.adView = [[SLAdView alloc] initWithEntity:@"seamless-example-mma"
                                          category:SLCategoryScience
                                            adSize:SLAdSizeMMA
                                rootViewController:self];
   self.adView.delegate = self;
   CGRect frame = self.adView.frame;
   frame.origin.y = self.view.bounds.size.height - SLAdSizeMMA.height;
   self.adView.frame = frame;
   [self.view addSubview:self.adView];
   [self.adView loadAd];
   ```
- Delegate methods
  ```Objective-C
  -(void)adViewDidLoad:(SLAdView*)adView{
  // ad load success
 }

  -(void)adViewDidFailToLoad:(SLAdView*)adView{
  // ad load failed
}
  ```

### Interstitial integration
- Import required headers

  ```Objective-C
    #import <Seamless/Seamless.h>
  ```
- Declare a SLInterstitialAdManager *adManager property in your view controller.

  ```Objective-C
    @property (nonatomic, strong) SLInterstitial * adManager;
  ```
- In viewDidLoad;

```Objective-C
    self.adManager = [[SLInterstitialAdManager alloc] initWithDelegate:self];

    __weak id selfWeak = self;

    [self.adManager
     getAdWithEntity:@"interstitial-detay"
     category:SLCategoryPolitics
     successBlock:^(MPInterstitialAdController *adController) {

         id selfStrong = selfWeak;

         if (selfStrong)
         {
             [adController showFromViewController:selfStrong];
         }

    } failureBlock:^(NSError *error) {
        NSLog(@"%@",error);
    }];
```

### Feed Ad Customization
- If you want to customize appearance of in-feed ads you can use SLAppearance class.
- You can set your ad containers insets:

![Alt text](/ReadmeAssets/customization/3.png "Container edge insets")
```Objective-C
     SLAppearance * appearance = [SLAppearance alloc] init];
     appearance.containerEdgeInsets = UIEdgeInsetsMake(10, 10, 10, 10);
```
>Your containers left and right insets shouldn't be greater than 22 pt!

- If your container width greater than display ads width, display ads also show in container.
You can set display ads bottom and top inset with container.

![Alt text](/ReadmeAssets/customization/4.png "display container")
```Objective-C
    appearance.displayAdBottomInset = 10.0;
    appearance.displayAdTopInset = 10.0;
```
- You can set your background colors and CTA Button image:

![Alt text](/ReadmeAssets/customization/2.png "colors")
```Objective-C
    appearance.maiaAdHeaderBackgroundColor = [UIColor lightGrayColor];  
    appearance.maiaAdFooterBackgroundColor = [UIColor grayColor];
    appearance.cellBackgroundColor = [UIColor whiteColor];
    appearance.containerBackgroundColor = [UIColor whiteColor];
    appearance.ctaButtonImage = [UIImage imageNamed:@"yourImage"];
```
- You can set your container and maia ads border line color, width and corner radius:

![Alt text](/ReadmeAssets/customization/1.png "Borders")
```Objective-C
    appearance.containerBorderWidth = 1.0;
    appearance.containerBorderLineColor = [UIColor blackColor];
    appearance.containerCornerRadius = 5.0;
    appearance.maiaAdBorderWidth = 0.5;
    appearance.maiaAdBorderLineColor = [UIColor blackColor];
    appearance.maiaAdCornerRadius = 3;
```
- For the text properties you can set font, size and text color:

![Alt text](/ReadmeAssets/customization/5.png "Texts")
```Objective-C
    appearance.maiaContainerTitleFont = [UIFont systemFontOfSize:15.0];
    appearance.maiaContainerTitleTextColor = [UIColor blackColor];
    appearance.maiaAppNameFont = [UIFont systemFontOfSize:14.0];
    appearance.maiaAppNameTextColor = [UIColor blackColor];
    appearance.maiaSponsorFont = [UIFont systemFontOfSize:11.0];
    appearance.maiaSponsorTextColor = [UIColor blackColor];
    appearance.maiaDescriptionFont = [UIFont systemFontOfSize:14.0];
    appearance.maiaDescriptionTextColor = [UIColor blackColor];
    appearance.maiaTaglineFont = [UIFont systemFontOfSize:14.0];
    appearance.maiaTaglineTextColor = [UIColor blackColor];
    appearance.maiaDownloadInfoFont = [UIFont systemFontOfSize:11.0];
    appearance.maiaDownloadInfoTextColor = [UIColor blackColor];
    appearance.maiaCTAFont = [UIFont systemFontOfSize:13.0];
    appearance.maiaCTATextColor = [UIColor blackColor];
```

### See sample project for usage
