import 'package:agora_desktop/core/constants/routes.dart';
import 'package:agora_desktop/features/home/data/support_model.dart';
import 'package:flutter/material.dart';
import 'package:flutter_ds_bfi/flutter_ds_bfi.dart';

import '../widgets/support_card.dart';

class HomeScreen extends StatelessWidget {
  HomeScreen({Key? key}) : super(key: key);

  final _supportList = <Support>[
    Support(
        customerName: 'Panji K.',
        status: 'Pending',
        noChannel: 'X123456',
        keterangan: 'Terdapat bug aplikasi',
        tipe: 'Pertanyaan')
  ];

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      body: Center(
        child: Padding(
          padding: const EdgeInsets.only(
            top: 32,
          ),
          child: Column(
            children: [
              DSText(
                data: 'Customer Support',
                textStyle: DSTextStyle.titleTextStyle,
              ),
              const SizedBox(
                height: 64,
              ),
              Expanded(
                child: ListView.builder(
                  padding: const EdgeInsets.only(
                    left: 64,
                    right: 64,
                    bottom: 32,
                  ),
                  itemBuilder: (context, index) {
                    return SupportCard(
                      support: _supportList[index],
                      onTap: () {
                        Navigator.pushNamed(context, videoCallScreen);
                      },
                    );
                  },
                  itemCount: _supportList.length,
                ),
              )
            ],
          ),
        ),
      ),
    );
  }
}
