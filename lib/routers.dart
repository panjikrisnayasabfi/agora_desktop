import 'package:agora_desktop/core/constants/routes.dart';
import 'package:agora_desktop/features/video_call/presentation/screens/video_call_screen.dart';
import 'package:agora_desktop/features/login/presentation/screens/login_screen.dart';
import 'package:flutter/material.dart';

import 'features/home/presentation/screens/home_screen.dart';

class Routers {
  static Route<dynamic> generateRoute(RouteSettings settings) {
    switch (settings.name) {
      case loginScreen:
        return PageRouteBuilder<dynamic>(
            pageBuilder: (_, __, ___) => LoginScreen(),
            settings: RouteSettings(name: settings.name),
            transitionsBuilder: (_, Animation<double> a, __, Widget c) =>
                FadeTransition(opacity: a, child: c));

      case homeScreen:
        return PageRouteBuilder<dynamic>(
            pageBuilder: (_, __, ___) => HomeScreen(),
            settings: RouteSettings(name: settings.name),
            transitionsBuilder: (_, Animation<double> a, __, Widget c) =>
                FadeTransition(opacity: a, child: c));

      case videoCallScreen:
        return PageRouteBuilder<dynamic>(
            pageBuilder: (_, __, ___) => const VideoCallScreen(),
            settings: RouteSettings(name: settings.name),
            transitionsBuilder: (_, Animation<double> a, __, Widget c) =>
                FadeTransition(opacity: a, child: c));

      default:
        return MaterialPageRoute<dynamic>(
            builder: (_) => Scaffold(
                  body: Center(
                      child: Text('No route defined for ${settings.name}')),
                ));
    }
  }
}
