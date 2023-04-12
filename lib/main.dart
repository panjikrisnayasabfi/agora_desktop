import 'package:agora_desktop/core/utils/strings_util.dart';
import 'package:agora_desktop/routers.dart';
import 'package:flutter/material.dart';

import 'core/constants/routes.dart';

void main() {
  runApp(const MyApp());
}

class MyApp extends StatelessWidget {
  const MyApp({super.key});

  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      title: Strings.appTitle,
      theme: ThemeData(
        primarySwatch: Colors.blue,
      ),
      initialRoute: loginScreen,
      onGenerateRoute: Routers.generateRoute,
    );
  }
}
