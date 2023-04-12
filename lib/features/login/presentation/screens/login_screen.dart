import 'package:agora_desktop/core/constants/routes.dart';
import 'package:flutter/material.dart';
import 'package:flutter_ds_bfi/flutter_ds_bfi.dart';

class LoginScreen extends StatelessWidget {
  LoginScreen({Key? key}) : super(key: key);

  final TextEditingController _noKontrakController = TextEditingController();

  void _login(BuildContext context) {
    if (_noKontrakController.text == 'agent') {
      Navigator.pushNamed(context, homeScreen);
    }
  }

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      body: Center(
        child: Padding(
          padding: const EdgeInsets.symmetric(
            vertical: 32,
            horizontal: 64,
          ),
          child: Column(
            children: [
              DSText(
                data: 'Customer Support App',
                textStyle: DSTextStyle.titleTextStyle,
              ),
              const SizedBox(
                height: 80,
              ),
              DSCustomTextField(
                hintText: 'No. Kontrak',
                controller: _noKontrakController,
              ),
              const SizedBox(
                height: 24,
              ),
              DSFilledButton(
                text: 'Login',
                buttonState: DSButtonState.Active,
                onTap: () {
                  _login(context);
                },
              ),
            ],
          ),
        ),
      ),
    );
  }
}
