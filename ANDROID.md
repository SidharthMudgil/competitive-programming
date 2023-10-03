## Android
OpenSource operating system based on linux kernel primarily used for mobile devices.

### Activity & Fragment
> Actvity is a single screen or user interface of the app that the user can interact with. It's one of the basic building blocks of an Android app.
>
> Fragment is a modular section or part in an activity that is reusable and has its own lifecycle. We can combine multiple fragments to create an ui for a single screen

### Activity & Fragment Lifecycle
| ![image](https://github.com/SidharthMudgil/competitive-programming/assets/68889544/7d2d3efd-ec93-4f9f-b6b5-6359f524529b) | ![image](https://github.com/SidharthMudgil/competitive-programming/assets/68889544/ec306232-7cf0-4f98-b38a-c38d5426ee53) |
| ---------------- | --------------- |

### Intents
> Messaging objects that are used to send data or perform some actions.
>
> - **Implicit:** Intents that does not specify any target or component, But instead a general action. for example opening an url.
> - **Explicit:** Intents that specifies a target package or class. for example starting a new activity.

### IntentFilter
> intent filter are used to filter out the type of intent the component will receive.

### Services
> services are used to run long-running tasks in background even when user is not interacting with the app.
>
> - **Started Service:** started using `startService` method and run even after closing the app.
> - **Bound Service:** bind to an component lifecycle and stops when the component dies.

### Foreground Service
> Special type of services that have UI component that user can interact with.  They shows notification to the user.

### Broadcast & BroadcastReceivers
> system wide events occurs on android devices that are broadcasted to every apps.
> BroadcastReceivers are classes used to receive these broadcast messages.

### AndroidManifest
> xml file that contains all the information about the app such as package name, activities, services, etc.

### Content Provider
> content provider is used to store data that can be shared among different apps and provide an interface for the apps to acces the data.

### Android Tools
> - **Android SDK:** set of tools and libraries that are used to build android applications.
> - **ADB:** commandline tool used to communicate with android devices & emulators.
> - **AAPT:** Android Asset Packaging Tool, is a command-line tool used to compile your app resources into a single binary file.
> - **Emulator:** used to emulate real android devices in computer, it provide a virtual environment to run android apps.

### Android Architecture
> - **Linux kernel:**  core of the Android system and provides the basic functionality, such as memory management, device drivers, and process scheduling.
> - **Android runtime (ART):** runtime environment for running android apps.
> - **Native libraries:** written in C or C++, providse low-level functionality, such as hardware access and graphics rendering.
> - **Android libraries:** provide a set of APIs that developers can use to develop Android apps.
> - **Android system apps:** pre-installed apps that come with every Android device.

### Android Architecture
> 1. **Services**
> 1. **Activities**
> 1. **Fragments**
> 1. **Broadcast Receievers**
> 1. **Content Providers**

### Context
> context of the current state of the application/object. It allows access to application-specific resources and classes, as well as up-calls for application-level operations, such as launching activities, broadcasting and receiving intents, etc.

### DDMS
> Dalvik Debug Monitor Server. tool that allows developers to monitor and debug android applications running on emulators or connected devices.

### Handling background tasks
> - **Service:** component in the android system that runs in the background and performs long-running operations, such as playing music. A service can run indefinitely or be started and stopped on demand.
> - **IntentService:** type of service that can handle multiple requests on a separate worker thread in a queue. It automatically stops itself when the task is completed.
> - **JobScheduler:** system service that allows you to schedule background tasks to run at specific times or conditions, such as when the device is idle or connected to a charger.
> - **WorkManager:** library introduced in Android Jetpack that provides a simple and flexible way to schedule and manage background tasks in your app.

### Handler, Asynctask, and Thread
> - **Handler:** class used to register to a thread and provides a simple channel to send data to this thread. Allows you communicate back with the UI thread from other background thread.
> - **AsyncTask:** class encapsulates the creation of a background process and the synchronization with the main thread. It also supports reporting progress of the running tasks.
> - **Thread:** core element of multithreading which a developer can use to perform background task.

### Launch Modes
> - **Standard:** Creates a new instance of the activity every time, allowing multiple instances within the same task.
> - **SingleTop:** Reuses the existing instance if it's on top, calling onNewIntent(), or creates a new instance.
> - **SingleTask:** Ensures only one instance in a new or existing task, clearing activities above it in the stack.
> - **SingleInstance:** A unique task is created for the activity, allowing no other activities in the same task.

### Runtime Permissions
> process where apps request specific permissions from the user while the app is running, typically in response to user actions, ensuring that sensitive device resources are accessed only with the user's explicit consent, enhancing security and privacy.

### MVVM
> MVVM is an Architectural design pattern that is used to separate business logic and the presentation logic of the UI.
> - **Model:** main logic of program that contains that and retrieved by the viewmodel.
> - **ViewModel:** defines properties and commands that can be used to bind data with views.
> - **View:** responsible for defining the layout, structure, and appearence of the UI.
![image](https://github.com/SidharthMudgil/competitive-programming/assets/68889544/17997910-5ed9-4f28-ad93-b034c745c858)

### Recycler Views
> Android UI component that allows us to create a scrolling list.
> - **Adapter:** adapters are used to adapt data for individual items. It binds data with the viewholders.
> - **ViewHolder:** helper class that draws layout for an individual items
> - **LayoutManager:** used to position items within recycler views.
> - **ItemAnimator:** class to change the animation for the recycler view.

### Room Database
> Android library that is part of jetpack components used for persistent storage that is made on the top of SQLite database.
> - **Entity:** represents a table within database, and each field acts as a column.
> - **Dao:** interface that is used to define database operations such as insert, delete, etc.
> - **Database:** responsible for creating the database and provide dao associated with the database.

### Retrofit
> HTTP Client for android applications that makes network requests, and api handling easy.
> - **ApiService:** interface that defines the API endpoints and their HTTP methods.
> - **Retrofit:** responsible for creating and configuring the HTTP client, defining the base URL for the API, and creating instances of API interfaces.
> - **Response:** class that represents the api response.

### Dependency Injection
> Dependency injection is a programming technique that makes a class independent of its dependencies. It achieves that by decoupling the usage of an object from its creation.
