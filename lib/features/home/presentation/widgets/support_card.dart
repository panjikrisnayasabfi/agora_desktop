import 'package:flutter/material.dart';
import 'package:flutter_ds_bfi/flutter_ds_bfi.dart';

import '../../data/support_model.dart';

class SupportCard extends StatelessWidget {
  const SupportCard({
    Key? key,
    required this.support,
    required this.onTap,
  }) : super(key: key);

  final Support support;
  final VoidCallback onTap;

  @override
  Widget build(BuildContext context) {
    return Card(
      margin: const EdgeInsets.only(bottom: 16),
      child: InkWell(
        onTap: () => onTap(),
        child: Padding(
          padding: const EdgeInsets.all(16),
          child: Column(
            crossAxisAlignment: CrossAxisAlignment.start,
            children: [
              DSText(
                data: support.customerName,
                textStyle: DSTextStyle.mediumStyle.copyWith(
                  fontWeight: FontWeight.bold,
                ),
              ),
              const SizedBox(
                height: 8,
              ),
              DSText(
                data: 'Status',
                textStyle: DSTextStyle.regularStyle.copyWith(
                  fontWeight: FontWeight.w500,
                ),
              ),
              DSText(
                data: support.status,
              ),
              const SizedBox(
                height: 4,
              ),
              DSText(
                data: 'No. Channel',
                textStyle: DSTextStyle.regularStyle.copyWith(
                  fontWeight: FontWeight.w500,
                ),
              ),
              DSText(
                data: support.noChannel,
              ),
              const SizedBox(
                height: 4,
              ),
              DSText(
                data: 'Keterangan',
                textStyle: DSTextStyle.regularStyle.copyWith(
                  fontWeight: FontWeight.w500,
                ),
              ),
              DSText(
                data: support.keterangan,
              ),
              const SizedBox(
                height: 4,
              ),
              DSText(
                data: 'Tipe',
                textStyle: DSTextStyle.regularStyle.copyWith(
                  fontWeight: FontWeight.w500,
                ),
              ),
              DSText(
                data: support.tipe,
              ),
            ],
          ),
        ),
      ),
    );
  }
}
